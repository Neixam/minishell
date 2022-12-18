/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:23:56 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:34:51 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "minishell.h"
#include "execute.h"

char	*ft_pathificator(char *s1, char *s2)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(s1, "/");
	tmp2 = ft_strjoin(tmp, s2);
	ft_free(tmp);
	return (tmp2);
}

char	*ft_get_path(t_hash_set *env, char *name)
{
	char	*var;
	char	**paths;
	char	*path;
	int		i;

	var = get_var(env, "PATH");
	if (!ft_strcmp("", var))
	{
		ft_free(var);
		return (ft_strdup(name));
	}
	paths = ft_split(var, ':');
	i = -1;
	while (paths[++i])
	{
		path = ft_pathificator(paths[i], name);
		if (access(path, F_OK) != -1)
			break ;
		ft_free(path);
	}
	if (!paths[i])
		path = ft_strdup(name);
	ft_free_tab(paths);
	return (path);
}

void	ft_parent_process(t_data *data, int pip[2])
{
	if (exec_father_signals())
		perror(data->prog_name);
	close(pip[1]);
	if (data->pipe == 1)
		if (dup2(pip[0], STDIN_FILENO) == -1)
			perror("dup2");
	close(pip[0]);
	data->fd_out = -1;
	data->fd_in = -1;
	if (dup2(data->save_stdout, STDOUT_FILENO) == -1)
		perror(data->prog_name);
}

void	ft_child_process(t_data *data, char **args, t_exec exec, int pip[2])
{
	char	*path;
	char	**env;

	if (data->fd_out == -1 && data->pipe == 1)
		if (dup2(pip[1], STDOUT_FILENO) == -1)
			perror("dup2");
	close(pip[1]);
	path = ft_get_path(data->env, *args);
	env = ft_set_env(data->env);
	pip[0] = exec(path, args, env);
	if (pip[0] == -1)
	{
		if (errno == 2)
			g_exit_status = 127;
		if (errno == 13 || errno == 20)
			g_exit_status = 126;
		if (ft_strchr(*args, '/'))
			perror(path);
		else
			ft_put_error(path, "command not found");
	}
	else
		g_exit_status = pip[0];
	ft_clean_memory();
	exit(g_exit_status);
}

void	ft_execute(t_data *data, char **args, t_exec exec)
{
	pid_t	pid;
	int		pip[2];

	if (pipe(pip) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		if (exec_child_signals())
			perror(data->prog_name);
		close(data->save_stdin);
		close(data->save_stdout);
		close(pip[0]);
		ft_child_process(data, args, exec, pip);
	}
	ft_parent_process(data, pip);
}
