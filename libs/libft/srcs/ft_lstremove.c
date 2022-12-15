/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:02:46 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/30 16:02:47 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstremove(t_list **lst, t_list *unit)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *lst;
	last = 0;
	while (tmp && tmp != unit)
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
