/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:22:33 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:22:56 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "rules.h"
#include "execute.h"

int	ft_my_env(const char *name, char *const*args, char *const*env)
{
	(void)name;
	(void)args;
	while (*env)
		printf("%s\n", *(env++));
	ft_clean_memory();
	exit(0);
}

void	ft_env(t_rules *rules)
{
	ft_execute(rules->data, rules->arg, ft_my_env);
}
