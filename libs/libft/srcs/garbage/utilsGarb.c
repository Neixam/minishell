/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsGarb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:33:48 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/06 17:29:10 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"
#include <stdlib.h>

static unsigned int	hash_code(void *ad, int size)
{
	return ((unsigned long)ad & (size - 1));
}

t_hash_set	*garbage(void)
{
	static t_hash_set	*garb = NULL;

	if (!garb)
	{
		garb = (t_hash_set *)malloc(sizeof(t_hash_set));
		if (!garb)
			exit(139);
		ft_bzero(garb, sizeof(t_hash_set));
		garb->entries = (t_list **)malloc(sizeof(t_list *) * 8);
		if (!garb->entries)
		{
			free(garb);
			exit(139);
		}
		ft_bzero(garb->entries, sizeof(t_list *) * 8);
		garb->capacity = 8;
	}
	return (garb);
}

static t_list	*ft_new_entry(void *cnt)
{
	t_list	*new_entry;

	new_entry = (t_list *)malloc(sizeof(t_list));
	if (!new_entry)
	{
		ft_clean_memory();
		exit(139);
	}
	new_entry->content = cnt;
	new_entry->next = NULL;
	return (new_entry);
}

static void	upgrade_garb(t_hash_set *garb)
{
	t_list	**new_entries;
	t_list	*e;
	int		i;

	new_entries = (t_list **)malloc(sizeof(t_list *) * (garb->capacity << 1));
	if (!new_entries)
	{
		ft_clean_memory();
		exit(139);
	}
	ft_bzero(new_entries, sizeof(t_list *) * (garb->capacity << 1));
	i = -1;
	while (++i < garb->capacity)
	{
		while (garb->entries[i])
		{
			e = garb->entries[i];
			ft_lstadd_front(
				new_entries + hash_code(e->content, garb->capacity << 1),
				ft_lstremove(garb->entries + i, e));
		}
	}
	garb->capacity <<= 1;
	free(garb->entries);
	garb->entries = new_entries;
}

void	ft_garb_add(void *content)
{
	t_hash_set	*garb;

	garb = garbage();
	ft_lstadd_front(garb->entries + hash_code(content, garb->capacity),
		ft_new_entry(content));
	garb->size++;
	if (garb->capacity >> 1 < garb->size)
		upgrade_garb(garb);
}
