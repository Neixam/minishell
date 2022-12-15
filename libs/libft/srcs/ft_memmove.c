/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:25:20 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/23 13:46:17 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	int		i;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	i = -1;
	if ((char *)src < d)
		while (n--)
			d[n] = ((char *)src)[n];
	else
		while ((size_t)++i < n)
			d[i] = ((char *)src)[i];
	return (dest);
}
