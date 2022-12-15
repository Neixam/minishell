/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:16:46 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 18:28:25 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "token.h"
#include "syntax.h"

void	ft_retrieve_literal(char *input, int *i, t_list **in)
{
	int				start;
	int 			end;

	start = *i;
	end = 1;
	while (input[*i + end] && ft_type_token(input[*i + end]) == LITERAL)
		end++;
	ft_lstadd_back(in,
	ft_lstnew(ft_new_token(ft_substr(input, start, end),LITERAL)));
	*i += end;
}


char	*ft_retrieve_variable(char *input, int *i, t_data *data)
{
	int		start;
	int 	end;
	char	*name;
	char	*ret;

	start = ++(*i);
	end = 0;
	while (input[end + *i] && ft_type_token(input[end + *i]) == LITERAL
		   && (ft_isalnum(input[end + *i]) || input[end + *i] == '_'))
		end++;
	*i += end;
	if (end == 0)
	{
		if (input[start] == '?')
		{
			(*i)++;
			return (get_var(data->env, "?"));
		}
		else
			return (ft_strdup("$"));
	}
	name = ft_substr(input, start, end);
	ret = get_var(data->env, name);
	ft_free(name);
	return (ret);
}

int ft_retrieve_quote(char *input, int *i, t_data *data, t_token_name type)
{
	int 	start;
	int		end;

	start = ++(*i);
	end = 0;
	while (input[end + *i] && ft_type_token(input[end + *i]) != type)
	{
		if (type == DOUBLE_QUOTE && ft_type_token(input[end + *i]) == VARIABLE)
		{
			if (start != *i + end)
				ft_lstadd_back(&data->input,ft_lstnew(ft_new_token(ft_substr(input, start, end), LITERAL)));
			*i += end;
			ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(ft_retrieve_variable(input, i, data), LITERAL)));
			end = 0;
			start = *i;
		}
		else
			end++;
	}
	if (!input[*i + end])
		return (1);
	ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(ft_substr(input, start, end), LITERAL)));
	*i += end + 1;
	return (0);
}

void	ft_retrieve_input(char *input, t_data *data)
{
	int 	i;
	int 	start;

	i = -1;
	start = 0;
	while (input[++i])
	{
		if (ft_type_token(input[i]) == WHITESPACE)
		{
			if (start != i)
				ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(ft_substr(input, start, i - start), LITERAL)));
			ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(ft_strdup(""), WHITESPACE)));
			start = i + 1;
		}
	}
	if (start != i)
		ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(ft_substr(input, start, i - start), LITERAL)));
}

void ft_fusion(t_list **input)
{
	t_list	*tmp;
	t_list	*to_delete;

	tmp = *input;
	while (tmp)
	{
		while (tmp->next
			&& !ft_token_cmp(tmp->next->content,tmp->content))
		{
			to_delete = ft_lstremove(&tmp, tmp->next);
			ft_fuse_token(tmp->content, to_delete->content);
			ft_lstdelone(to_delete, ft_free_token);
		}
		tmp = tmp->next;
	}
}

int	parsing(char *input, t_data *data)
{
	int 			i;
	t_token_name	type;

	i = 0;
	while (input[i])
	{
		type = ft_type_token(input[i]);
		if (type == LITERAL)
			ft_retrieve_literal(input, &i, &data->input);
		else if (type == VARIABLE)
			ft_retrieve_input(ft_retrieve_variable(input, &i, data), data);
		else if (type == SIMPLE_QUOTE || type == DOUBLE_QUOTE)
		{
			if (ft_retrieve_quote(input, &i, data, type))
				return (1);
		}
		else
		{
			ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(ft_strdup(""), type)));
			i++;
		}
	}
	ft_fusion(&data->input);
	if (syntax_check(data))
		return (1);
	return (0);
}
