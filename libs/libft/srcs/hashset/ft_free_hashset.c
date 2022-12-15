/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_hashset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:42 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/30 16:01:43 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_hashset(t_hash_set *set, void (*del)(void *))
{
	while (set->capacity-- >= 0)
		ft_lstclear(set->entries + set->capacity, del);
	ft_free(set->entries);
	ft_free(set);
}
