/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:50:41 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 13:59:22 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)ft_malloc(sizeof(char) * (len + 1));
	len = 0;
	while (*s1)
		ret[len++] = *(s1++);
	while (*s2)
		ret[len++] = *(s2++);
	ret[len] = 0;
	return (ret);
}
