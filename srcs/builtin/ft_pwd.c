/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:19:03 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:21:54 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "rules.h"
#include "execute.h"

int	ft_my_pwd(const char *name, char *const*args, char *const*env)
{
	t_hash_set	*tmp_env;
	char		*pwd;

	(void)name;
	(void)args;
	tmp_env = init_env((char **)env);
	pwd = get_var(tmp_env, "PWD");
	if (!pwd)
	{
		perror(name);
		ft_clean_memory();
		exit(1);
	}
	printf("%s\n", pwd);
	ft_clean_memory();
	exit(0);
}

void	ft_pwd(t_rules *rules)
{
	ft_execute(rules->data, rules->arg, ft_my_pwd);
}
