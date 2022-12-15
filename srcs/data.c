/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:55:39 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/28 13:21:41 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "minishell.h"
#include "libft.h"
#include "garbage.h"

t_hash_set 	*init_env(char **env)
{
	t_hash_set *ret;

	ret = ft_new_hashset(ft_hashcode_var);
	while (*env)
		ft_put_element(ret, *(env++));
	return (ret);
}

void	init_minishell(t_data *data, char *name, char **env)
{
	ft_bzero(data, sizeof(*data));
	data->env = init_env(env);
	data->initpwd = getcwd(NULL, 0);
	if (!data->initpwd)
		perror("y a pas de chemin la");
	else
	{
		set_var("PWD", data->initpwd, data->env);
		ft_garb_add(data->initpwd);
	}
	data->prog_name = ft_strdup(name);
	data->prompt = ft_strjoin(name, ">");
	data->save_stdout = dup(STDOUT_FILENO);
	data->save_stdin = dup(STDIN_FILENO);
	if (data->save_stdout == -1 || data->save_stdin == -1)
		perror(data->prog_name);
}