/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:02:53 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/30 16:24:59 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstremove_elem(t_list **lst, void *elem, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	t_list	*last;

	tmp = *lst;
	last = 0;
	while (tmp && cmp(tmp->content, elem))
	{
		last = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return (0);
	if (last)
		last->next = tmp->next;
	else
		*lst = tmp->next;
	tmp->next = 0;
	return (tmp);
}
