/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_depth_first_iter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:57:04 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 14:57:20 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_depth_first_iter(t_tree *tree, void (*f)(void *))
{
	if (!tree)
		return ;
	f(tree->content);
	ft_depth_first_iter(tree->child, f);
	ft_depth_first_iter(tree->bro, f);
}
