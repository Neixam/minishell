/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:28:13 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/23 13:23:06 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
