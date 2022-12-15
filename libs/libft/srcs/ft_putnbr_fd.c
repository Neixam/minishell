/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:30:37 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/27 14:46:51 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_aux(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (ft_putnbr_aux(-n, fd));
	}
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	ft_putnbr_aux(n / 10, fd);
	ft_putnbr_aux(n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr_aux(n, fd);
}
