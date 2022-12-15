/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:14:16 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 14:00:01 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*ret;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ret = (char *)ft_malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		ret[i] = f(i, *(s++));
	ret[i] = 0;
	return (ret);
}
