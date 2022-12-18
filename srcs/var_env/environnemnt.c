/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnemnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:37:51 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:14:29 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_var_cmp(void *a, void *b)
{
	int		i;
	char	*name;
	char	*elem;

	elem = (char *)a;
	name = (char *)b;
	i = 0;
	while (elem[i] == name[i] && elem[i] && name[i])
		i++;
	if (!name[i] && elem[i] == '=')
		return (0);
	return (elem[i] - name[i]);
}

int	ft_hashcode_var(char *var)
{
	int	hashcode;
	int	multiplier;

	hashcode = 0;
	multiplier = 1;
	while (*var && *var != '=')
	{
		hashcode += *(var++) * multiplier;
		multiplier = (multiplier << 5) - multiplier;
	}
	return (hashcode);
}

char	**ft_set_env(t_hash_set *set)
{
	char	**ret;

	ret = ft_collect(set, sizeof(char *), ft_coll_string);
	return (ret);
}
