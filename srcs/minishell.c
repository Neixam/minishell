/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:07:56 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:26:06 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "garbage.h"
#include "token.h"
#include "rules.h"
#include "execute.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	ft_retrieve_prompt(t_data *data)
{
	char	*buf;
	int		ret;

	buf = readline(data->prompt);
	if (!buf)
	{
		ft_clean_memory();
		ft_putendl_fd("exit", 2);
		exit(g_exit_status);
	}
	ft_garb_add(buf);
	ret = parsing(buf, data);
	if (ret)
	{
		printf("%s: syntax error near unexpected token `%s' in line %d\n",
			data->prog_name, data->error, data->line);
		g_exit_status = 2;
	}
	add_history(buf);
	ft_free(buf);
	return (ret);
}

void	reset_minishell(t_data *data)
{
	ft_lstclear(&data->input, ft_free_token);
	ft_destroy_tree(&data->abstract_tree, ft_free_rules);
	data->fd_in = -1;
	data->fd_out = -1;
	data->op_err = 0;
	data->pipe = -1;
	if (data->error)
		ft_free(data->error);
	data->error = 0;
	data->line++;
}

int	ft_retrieve_status(int exit_status, int *first)
{
	if (WIFSIGNALED(exit_status))
	{
		if (WTERMSIG(exit_status) == SIGINT && *first)
			printf("\n");
		if (WTERMSIG(exit_status) == SIGQUIT && *first)
			printf("Quit (core dumped)\n");
		*first = 0;
		return (128 + WTERMSIG(exit_status));
	}
	return (WEXITSTATUS(exit_status));
}

void	list_exec(t_data *data)
{
	pid_t	last_pid;
	pid_t	pid;
	int		exit_status;
	int		first;

	ft_depth_first_iter(data->abstract_tree, dispatch);
	if (dup2(data->save_stdout, STDOUT_FILENO) == -1)
		perror(data->prog_name);
	if (dup2(data->save_stdin, STDIN_FILENO) == -1)
		perror(data->prog_name);
	last_pid = -1;
	first = 1;
	while (1)
	{
		pid = waitpid(0, &exit_status, 0);
		if (pid == -1)
			return ;
		if (pid > last_pid)
		{
			last_pid = pid;
			g_exit_status = ft_retrieve_status(exit_status, &first);
		}
	}
}

void	start_minishell(t_data *data)
{
	while (1)
	{
		reset_minishell(data);
		if (prompt_signals())
			return (perror(data->prog_name));
		if (!ft_retrieve_prompt(data))
			list_exec(data);
	}
}
