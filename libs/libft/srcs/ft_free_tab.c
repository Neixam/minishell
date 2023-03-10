/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:23:09 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/06 17:27:55 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(void *a)
{
	int		i;
	char	**tab;

	tab = (char **)a;
	i = -1;
	while (tab[++i])
		ft_free(tab[i]);
	ft_free(tab);
}
