/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:48:10 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/27 18:21:33 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*s;
	size_t	j;

	if (!*little)
		return ((char *)big);
	if (!*big || !len)
		return (0);
	s = (char *)big - 1;
	while (*(++s) && len--)
	{
		j = 0;
		while (s[j] && ((char *)little)[j] && ((char *)little)[j] == s[j] &&
				len >= j)
			j++;
		if (!((char *)little)[j])
			return (s);
	}
	return (0);
}
