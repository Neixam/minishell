/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:36:38 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:37:00 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_token	*token;
	char	*file;

	token = (*cmd)->content;
	*cmd = (*cmd)->next;
	if (!*cmd)
	{
		data->error = ft_strdup("newline");
		return (1);
	}
	file = ft_file_check(cmd);
	if (!file)
	{
		data->error = ft_strdup(((t_token *)(*cmd)->content)->value);
		return (1);
	}
	*tree = ft_new_node(ft_new_rules(data, token->name, file));
	return (0);
}

int	ft_redir_check(t_data *data, t_list **cmd, t_tree **tree)
{
	t_tree	*tmp;
	int		ret;

	ft_skip_space(cmd);
	while (*cmd && ft_is_redirect(ft_get_name((*cmd)->content)))
	{
		tmp = 0;
		ret = ft_choose_redir(data, cmd, &tmp);
		ft_add_bro(tree, tmp);
		if (ret)
			return (ret);
		ft_skip_space(cmd);
	}
	return (0);
}
