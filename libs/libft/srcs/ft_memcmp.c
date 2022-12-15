/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:34:32 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/23 16:35:55 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	if (!n)
		return (n);
	i = 0;
	while (--n && ((char *)s1)[i] == ((char *)s2)[i])
		i++;
	return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
}
