/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:38:08 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:43:15 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include "token.h"
#include "rules.h"
#include "garbage.h"

int	ft_is_redirect(t_token_name token)
{
	return (token == REDIR_OUT || token == HEREDOC
		|| token == REDIR_IN || token == APPEND);
}

int	ft_skip_redirect(t_list **cmd)
{
	*cmd = (*cmd)->next;
	ft_skip_space(cmd);
	if (!*cmd || ft_get_name((*cmd)->content) != LITERAL)
		return (1);
	return (0);
}

int	ft_count_arg(t_list *cmd)
{
	int			ret;
	t_token		*token;

	ret = 0;
	while (cmd)
	{
		ft_skip_space(&cmd);
		if (!cmd)
			return (ret);
		if (ft_is_redirect(ft_get_name(cmd->content)))
		{
			if (ft_skip_redirect(&cmd))
				return (ret);
		}
		else
		{
			token = (t_token *)cmd->content;
			if (token->name != LITERAL)
				return (ret);
			ret++;
		}
		cmd = cmd->next;
	}
	return (ret);
}

int	ft_argument_check(t_data *data, t_list **cmd, t_tree **tree, char ***ret)
{
	int	i;

	*ret = (char **)ft_malloc(sizeof(char *) * (ft_count_arg(*cmd) + 1));
	i = 0;
	while (*cmd)
	{
		if (ft_redir_check(data, cmd, tree))
			return (1);
		ft_skip_space(cmd);
		if (!*cmd || ft_get_name((*cmd)->content) != LITERAL)
			break ;
		(*ret)[i++] = ft_strdup(((t_token *)(*cmd)->content)->value);
		*cmd = (*cmd)->next;
	}
	(*ret)[i] = 0;
	return (0);
}

int	ft_program_check(t_data *data, t_list **cmd, t_tree **tree)
{
	t_token	*token;
	char	**args;

	ft_skip_space(cmd);
	if (!*cmd)
		return (0);
	token = (*cmd)->content;
	if (ft_get_name(token) != LITERAL)
		return (0);
	if (ft_argument_check(data, cmd, tree, &args))
		return (1);
	ft_add_bro(tree, ft_new_node(ft_new_rules(data,
				ft_literal_value(token),
				args)));
	return (0);
}
