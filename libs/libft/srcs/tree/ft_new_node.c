/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:54:34 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 14:54:58 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_new_node(void *content)
{
	t_tree	*ret;

	ret = (t_tree *)ft_malloc(sizeof(t_tree));
	ret->content = content;
	ret->bro = NULL;
	ret->child = NULL;
	return (ret);
}
