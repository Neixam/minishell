/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_hashset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:07:42 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/28 13:15:52 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash_set	*ft_new_hashset(int (*hashcode)())
{
	t_hash_set	*ret;

	ret = (t_hash_set *)ft_malloc(sizeof(t_hash_set));
	ret->hashcode = hashcode;
	ret->size = 0;
	ret->capacity = 2;
	ret->entries = (t_list **)ft_malloc(sizeof(t_list *) * 2);
	ft_bzero(ret->entries, ret->capacity * sizeof(t_list *));
	return (ret);
}
