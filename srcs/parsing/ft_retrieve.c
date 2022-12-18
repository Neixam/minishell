/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:45:51 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:13:34 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

void	ft_retrieve_literal(char *input, int *i, t_list **in)
{
	int	start;
	int	end;

	start = *i;
	end = 1;
	while (input[*i + end] && ft_type_token(input[*i + end]) == LITERAL)
		end++;
	ft_lstadd_back(in,
		ft_lstnew(ft_new_token(ft_substr(input, start, end), LITERAL)));
	*i += end;
}

char	*ft_retrieve_variable(char *input, int *i, t_data *data)
{
	int		start;
	int		end;
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

void	ft_retrieve_input(char *input, t_data *data)
{
	int	i;
	int	start;

	i = -1;
	start = 0;
	while (input[++i])
	{
		if (ft_type_token(input[i]) == WHITESPACE)
		{
			if (start != i)
				ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(ft_substr(
								input, start, i - start), LITERAL)));
			ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(ft_strdup(" "),
						WHITESPACE)));
			start = i + 1;
		}
	}
	if (start != i)
		ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(
					ft_substr(input, start, i - start), LITERAL)));
}

int	ft_adding_var(t_data *data, char *input, int *i, int end)
{
	*i += end;
	ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(
				ft_retrieve_variable(input, i, data), LITERAL)));
	return (0);
}

int	ft_retrieve_quote(char *input, int *i, t_data *data, t_token_name type)
{
	int	start;
	int	end;

	start = ++(*i);
	end = 0;
	while (input[end + *i] && ft_type_token(input[end + *i]) != type)
	{
		if (type == DOUBLE_QUOTE && ft_type_token(input[end + *i]) == VARIABLE)
		{
			if (start != *i + end)
				ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(
							ft_substr(input, start, end), LITERAL)));
			end = ft_adding_var(data, input, i, end);
			start = *i;
		}
		else
			end++;
	}
	if (!input[*i + end])
		return (1);
	ft_lstadd_back(&data->input, ft_lstnew(ft_new_token(
				ft_substr(input, start, end), LITERAL)));
	*i += end + 1;
	return (0);
}
