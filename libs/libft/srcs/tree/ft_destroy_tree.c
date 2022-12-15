/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:55:22 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 14:56:37 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_destroy_tree(t_tree **tree, void (*del)(void *))
{
	if (!*tree)
		return ;
	ft_destroy_tree(&(*tree)->child, del);
	ft_destroy_tree(&(*tree)->bro, del);
	if (del)
		del((*tree)->content);
	ft_free(*tree);
	*tree = 0;
}
