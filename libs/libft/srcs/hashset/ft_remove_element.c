/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:02:35 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/06 17:25:22 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_remove_element(t_hash_set *set, void *element, int (*cmp)(void *,
			void *))
{
	t_list	*elem;
	void	*ret;

	elem = ft_lstremove_elem(&set->entries[ft_hashcode(set, element)],
			element, cmp);
	if (!elem)
		return (0);
	ret = elem->content;
	ft_free(elem);
	return (ret);
}
