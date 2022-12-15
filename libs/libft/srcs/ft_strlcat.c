/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:35 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/27 18:26:47 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	len_d;
	char	*s;

	len_d = ft_strlen(dst);
	if (size <= len_d)
		return (size + ft_strlen(src));
	size -= len_d;
	i = 0;
	s = (char *)src;
	while (--size && *s)
		dst[len_d + i++] = *(s++);
	dst[len_d + i] = 0;
	return (ft_strlen(src) + len_d);
}
