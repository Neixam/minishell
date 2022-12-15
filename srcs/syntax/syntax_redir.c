#include "rules.h"
#include "syntax.h"

char	*ft_file_check(t_list **cmd)
{
	t_token	*token;

	ft_skip_space(cmd);
	if (!*cmd)
		return (0);
	token = (t_token *)(*cmd)->content;
	if (token->name != LITERAL)
		return (0);
	*cmd = (*cmd)->next;
	return (token->value);
}

int	ft_choose_redir(t_data *data, t_list **cmd, t_tree **tree)
{
	t_token_name	token;
	char			*file;

	token = ft_get_name((*cmd)->content);
	*cmd = (*cmd)->next;
	if (!*cmd)
		return (1);
	file = ft_file_check(cmd);
	if (!file)
		return (1);
	*tree = ft_new_node(ft_new_rules(data, token, file));
	return (0);
}

int	ft_redir_check(t_data *data, t_list **cmd, t_tree **tree)
{
	t_tree	*tmp;
	int		ret;

	ft_skip_space(cmd);
	if (!*cmd)
		return (0);
	while (ft_get_name((*cmd)->content) == REDIR_IN
		   || ft_get_name((*cmd)->content) == HEREDOC
		   || ft_get_name((*cmd)->content) == REDIR_OUT
		   || ft_get_name((*cmd)->content) == APPEND)
	{
		tmp = 0;
		ret = ft_choose_redir(data, cmd, &tmp);
		ft_add_bro(tree, tmp);
		if (ret)
			return (ret);
		ft_skip_space(cmd);
		if (!*cmd)
			return (0);
	}
	return (0);
}