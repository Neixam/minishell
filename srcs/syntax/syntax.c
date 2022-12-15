#include "minishell.h"
#include "token.h"
#include "rules.h"
#include "syntax.h"

void	ft_skip_space(t_list **cmd)
{
	while (*cmd)
	{
		if (ft_get_name((*cmd)->content) != WHITESPACE)
			return ;
		*cmd = (*cmd)->next;
	}
}

int ft_cmd_check(t_data *data, t_list **cmd, t_tree **tree)
{
	t_tree	*tmp;
	t_tree	*tmp2;

	tmp2 = 0;
	ft_skip_space(cmd);
	if (!*cmd)
		return (0);
	if (ft_redir_check(data, cmd, tree))
		return (1);
	tmp = ft_program_check(data, cmd);
	if (ft_redir_check(data, cmd, &tmp2))
	{
		ft_destroy_tree(&tmp, ft_free_rules);
		ft_destroy_tree(&tmp2, ft_free_rules);
		return (1);
	}
	ft_add_bro(tree, tmp2);
	ft_add_bro(tree, tmp);
	if (!*tree)
		return (0);
	tmp = ft_new_node(ft_new_rules(data, CMD, "CMD"));
	tmp2 = *tree;
	*tree = tmp;
	ft_add_child(tree, tmp2);
	return (0);
}

int	ft_pipe_check(t_data *data, t_list **cmd, t_tree **tree)
{
	t_tree	*tmp;
	t_tree	*tmp2;

	tmp2 = 0;
	if (ft_get_name((*cmd)->content) == PIPE)
	{
		tmp = ft_new_node(ft_new_rules(data, PIPE, "|"));
		ft_add_child(&tmp, *tree);
		*cmd = (*cmd)->next;
		if (ft_start_check(data, cmd, &tmp2))
		{
			ft_destroy_tree(&tmp2, ft_free_rules);
			*tree = tmp;
			return (1);
		}
		ft_add_child(&tmp, tmp2);
		*tree = tmp;
	}
	return (0);
}

int	ft_start_check(t_data *data, t_list **cmd, t_tree **tree)
{
	ft_skip_space(cmd);
	if (!*cmd)
		return (1);
	if (ft_cmd_check(data, cmd, tree))
		return (1);
	ft_skip_space(cmd);
	if (!*cmd)
		return (0);
	return (ft_pipe_check(data, cmd, tree));
}

int	syntax_check(t_data *data)
{
	int 	ret;
	t_list	*cmd;

	data->abstract_tree = 0;
	cmd = data->input;
	ret = ft_start_check(data, &cmd, &data->abstract_tree);
	return (ret);
}