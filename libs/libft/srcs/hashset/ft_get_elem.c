/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:48 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/30 16:21:43 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_get_elem(t_hash_set *set, void *elem, int (*cmp)(void *, void *))
{
	t_list	*entry;

	entry = set->entries[ft_hashcode(set, elem)];
	while (entry && cmp(entry->content, elem))
		entry = entry->next;
	if (!entry)
		return (0);
	return (entry->content);
}
