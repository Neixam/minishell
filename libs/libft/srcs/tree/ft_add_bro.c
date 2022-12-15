/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_bro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:45:04 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 14:47:13 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_bro(t_tree **tree, t_tree *node)
{
	t_tree	*tmp;

	if (!*tree)
	{
		*tree = node;
		return ;
	}
	tmp = *tree;
	while (tmp->bro)
		tmp = tmp->bro;
	tmp->bro = node;
}
