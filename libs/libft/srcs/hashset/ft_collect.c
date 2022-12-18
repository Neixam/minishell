/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:12:31 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:13:06 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_collect(t_hash_set *set, size_t size, void (*collector)(void *,
		void *))
{
	int		i;
	t_list	*entry;
	void	*ret;

	i = -1;
	ret = ft_calloc((set->size + 1), size);
	while (++i < set->capacity)
	{
		entry = set->entries[i];
		while (entry)
		{
			collector(ret, entry->content);
			entry = entry->next;
		}
	}
	return (ret);
}
