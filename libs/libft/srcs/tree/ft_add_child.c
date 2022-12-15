/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:47:38 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 14:51:03 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_child(t_tree **tree, t_tree *node)
{
	if (!*tree)
	{
		*tree = node;
		return ;
	}
	return (ft_add_bro(&(*tree)->child, node));
}
