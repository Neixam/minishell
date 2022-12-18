/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:24:24 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 16:42:39 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"
#include "libft.h"
#include <stdlib.h>

static int	hash_code(void *ad, int size)
{
	return ((unsigned long)ad & (size - 1));
}

void	ft_clean_entries(t_list **entries)
{
	if (!*entries)
		return ;
	ft_clean_entries(&(*entries)->next);
	free((*entries)->content);
	free(*entries);
	*entries = NULL;
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_clean_memory();
		exit(139);
	}
	ft_garb_add(ptr);
	return (ptr);
}

void	ft_free(void *ad)
{
	t_hash_set	*garb;
	t_list		*entry;

	garb = garbage();
	entry = ft_lstremove_elem(garb->entries + hash_code(ad, garb->capacity), ad,
			ft_adcmp);
	if (!entry)
		return ;
	free(ad);
	free(entry);
}

void	ft_clean_memory(void)
{
	t_hash_set	*garb;
	int			i;

	garb = garbage();
	i = -1;
	while (++i < garb->capacity)
		ft_clean_entries(garb->entries + i);
	free(garb->entries);
	free(garb);
}
