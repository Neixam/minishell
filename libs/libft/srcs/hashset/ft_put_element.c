/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:17:03 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/06 17:26:14 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	upgrade(t_hash_set *set)
{
	t_list	**new_entries;
	t_list	*entry;
	int		i;
	int		len;

	len = set->capacity;
	set->capacity <<= 1;
	new_entries = (t_list **)ft_malloc(sizeof(t_list *) * set->capacity);
	ft_bzero(new_entries, sizeof(t_list *) * set->capacity);
	i = -1;
	while (++i < len)
	{
		while (set->entries[i])
		{
			entry = set->entries[i];
			ft_lstadd_front(
				new_entries + ft_hashcode(set, entry->content),
				ft_lstremove(set->entries + i, entry));
		}
	}
	ft_free(set->entries);
	set->entries = new_entries;
}

void	ft_put_element(t_hash_set *set, void *element)
{
	ft_lstadd_front(set->entries + ft_hashcode(set, element),
		ft_lstnew(element));
	set->size++;
	if (set->capacity >> 1 < set->size)
		upgrade(set);
}
