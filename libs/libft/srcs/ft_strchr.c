/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:40:07 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 11:49:06 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c == 0)
		return (&((char *)s)[ft_strlen(s)]);
	i = -1;
	while (((char *)s)[++i])
		if (((char *)s)[i] == (char)c)
			return (&((char *)s)[i]);
	return (0);
}
