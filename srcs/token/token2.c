/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:26:57 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:28:16 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"

t_token	*ft_new_token(char *value, t_token_name name)
{
	t_token	*ret;

	ret = (t_token *)ft_malloc(sizeof(t_token));
	ret->value = value;
	ret->name = name;
	return (ret);
}

void	ft_free_token(void *token)
{
	ft_free(((t_token *)token)->value);
	ft_free(token);
}

t_token_name	ft_get_name(void *t)
{
	return (((t_token *)t)->name);
}
