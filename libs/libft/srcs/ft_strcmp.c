/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:49:16 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/27 19:43:31 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (((char *)s1)[i] && ((char *)s2)[i] &&
			((char *)s1)[i] == ((char *)s2)[i])
		i++;
	return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
}
