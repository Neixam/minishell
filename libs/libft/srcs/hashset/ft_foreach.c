/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:35 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/30 16:22:08 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(t_hash_set *set, void (*f)(void *))
{
	int		i;
	t_list	*entry;

	i = -1;
	while (++i < set->capacity)
	{
		entry = set->entries[i];
		while (entry)
		{
			f(entry->content);
			entry = entry->next;
		}
	}
}
