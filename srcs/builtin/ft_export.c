/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:34:07 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:47:00 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rules.h"
#include "execute.h"

int	ft_make_export(t_hash_set *env, char **args)
{
	char	**split_arg;
	char	*name;
	char	*things;
	int		err;

	err = 0;
	while (*args)
	{
		things = ft_strchr(*args, '=');
		if (things)
		{
			split_arg = ft_split(*args, '=');
			name = split_arg[0];
			if (ft_is_varname(name))
				set_var(name, things + 1, env);
			else
			{
				ft_put_error(*args, "not a valid identifier");
				err = 1;
			}
			ft_free_tab(split_arg);
		}
		args++;
	}
	return (err);
}

int	ft_my_export(const char *name, char *const*args, char *const*env)
{
	t_hash_set	*my_env;
	int			ret;

	(void)name;
	my_env = init_env((char **)env);
	ret = ft_make_export(my_env, (char **)args + 1);
	ft_clean_memory();
	exit(ret);
}

void	ft_export(t_rules *rules)
{
	if (rules->data->pipe != -1)
		ft_execute(rules->data, rules->arg, ft_my_export);
	else
		g_exit_status = ft_make_export(rules->data->env,
				(char **)rules->arg + 1);
}
