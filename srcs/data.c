/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:55:39 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:24:47 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "minishell.h"
#include "libft.h"
#include "garbage.h"
#include "rules.h"

void	ft_delete_data(t_data *data)
{
	ft_free_hashset(data->env, ft_free);
	if (data->initpwd)
		ft_free(data->initpwd);
	ft_free(data->prog_name);
	ft_free(data->prompt);
	ft_free(data->error);
	if (data->save_stdin != -1)
		close(data->save_stdin);
	if (data->save_stdout != -1)
		close(data->save_stdout);
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
	ft_destroy_tree(&data->abstract_tree, ft_free_rules);
	ft_lstclear(&data->input, ft_free_token);
}

t_hash_set	*init_env(char **env)
{
	t_hash_set	*ret;

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
		perror(name);
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
