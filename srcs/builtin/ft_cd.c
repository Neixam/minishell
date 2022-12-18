/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:29:15 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:47:22 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "rules.h"
#include "execute.h"

int	ft_switch_pwd(t_data *data)
{
	char	*current_path;

	current_path = getcwd(0, 0);
	if (!current_path)
	{
		perror("getcwd");
		return (1);
	}
	if (data->initpwd)
	{
		set_var("OLDPWD", data->initpwd, data->env);
		ft_free(data->initpwd);
	}
	data->initpwd = ft_strdup(current_path);
	free(current_path);
	set_var("PWD", data->initpwd, data->env);
	return (0);
}

int	ft_make_cd(t_data *data, char **args)
{
	if (!*args || *(args + 1) || chdir(*args) == -1)
	{
		if (!*args)
			ft_put_error("cd", "not enough argument");
		else if (*(args + 1))
			ft_put_error("cd", "too many argument");
		else
			perror("cd");
		return (1);
	}
	if (!data)
		return (0);
	if (ft_switch_pwd(data))
		return (1);
	return (0);
}

int	ft_my_cd(const char *name, char *const*args, char *const*env)
{
	int	ret;

	(void)name;
	(void)env;
	ret = ft_make_cd(0, (char **)args + 1);
	ft_clean_memory();
	exit(ret);
}

void	ft_cd(t_rules *rules)
{
	if (rules->data->pipe != -1)
		ft_execute(rules->data, rules->arg, ft_my_cd);
	else
		g_exit_status = ft_make_cd(rules->data,
				(char **)rules->arg + 1);
}
