/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:46:49 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/23 13:54:49 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	char	*s;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	s = (char *)src;
	while (--size && *s)
		dst[i++] = *(s++);
	dst[i] = 0;
	return (ft_strlen(src));
}
