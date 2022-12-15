/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_breadth_first_iter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:57:39 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 14:59:23 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*pop_head(t_list **queue)
{
	t_list	*head;
	t_tree	*ret;

	head = *queue;
	*queue = (*queue)->next;
	head->next = 0;
	ret = (t_tree *)head->content;
	ft_free(head);
	return (ret);
}

void	ft_breadth_first_iter(t_tree *tree, void (*f)(void *))
{
	t_list	*queue;
	t_tree	*tmp;

	queue = 0;
	ft_lstadd_back(&queue, ft_lstnew(tree));
	while (queue)
	{
		tmp = pop_head(&queue);
		f(tmp->content);
		tmp = tmp->child;
		while (tmp)
		{
			ft_lstadd_back(&queue, ft_lstnew(tmp));
			tmp = tmp->bro;
		}
	}
}
