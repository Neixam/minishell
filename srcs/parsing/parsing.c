/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:16:46 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:45:34 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "token.h"
#include "syntax.h"

void	ft_fusion(t_list **input)
{
	t_list	*tmp;
	t_list	*to_delete;

	tmp = *input;
	while (tmp)
	{
		while (tmp->next
			&& !ft_token_cmp(tmp->next->content, tmp->content))
		{
			to_delete = ft_lstremove(&tmp, tmp->next);
			ft_fuse_token(tmp->content, to_delete->content);
			ft_lstdelone(to_delete, ft_free_token);
		}
		tmp = tmp->next;
	}
}

int	parse_token(char *input, int *i, t_data *data, t_token_name type)
{
	if (type == LITERAL)
		ft_retrieve_literal(input, i, &data->input);
	else if (type == VARIABLE)
		ft_retrieve_input(ft_retrieve_variable(input, i, data), data);
	else if (type == SIMPLE_QUOTE || type == DOUBLE_QUOTE)
	{
		if (ft_retrieve_quote(input, i, data, type))
		{
			data->error = ft_strdup("newline");
			return (1);
		}
	}
	else
	{
		ft_lstadd_back(&data->input,
			ft_lstnew(ft_new_token(ft_substr(input, *i, 1), type)));
		(*i)++;
	}
	return (0);
}

int	parsing(char *input, t_data *data)
{
	int	i;

	i = 0;
	while (input[i])
		if (parse_token(input, &i, data, ft_type_token(input[i])))
			return (1);
	ft_fusion(&data->input);
	if (syntax_check(data))
		return (1);
	return (0);
}
