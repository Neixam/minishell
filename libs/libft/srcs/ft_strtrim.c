/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:57:33 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 13:58:50 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_calc(char const *s, char const *set)
{
	int	len;

	while (*s && ft_strchr(set, *s))
		s++;
	len = ft_strlen(s);
	while (len > 0 && ft_strchr(set, s[len - 1]))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	len = ft_size_calc(s1, set);
	ret = (char *)ft_malloc(sizeof(char) * (len + 1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = 0;
	while (len--)
		ret[i++] = *(s1++);
	ret[i] = 0;
	return (ret);
}
