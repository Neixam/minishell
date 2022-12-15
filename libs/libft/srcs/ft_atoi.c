/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:26:12 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/27 19:47:00 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(int c)
{
	return (c == '\n' || c == '\t' || c == ' ' || c == '\r' || c == '\f'
		|| c == '\v');
}

static int	ft_panic(int neg)
{
	if (neg == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned long long int	val;
	int						neg;
	char					*s;

	s = (char *)nptr;
	while (ft_isblank(*s))
		s++;
	neg = 1;
	if (*s == '+' || *s == '-')
		if (*(s++) == '-')
			neg = -1;
	val = 0;
	while (ft_isdigit(*s))
	{
		if (val > val * 10 + *s - '0')
			return (ft_panic(neg));
		val = val * 10 + *(s++) - '0';
	}
	return (val * (long long)neg);
}
