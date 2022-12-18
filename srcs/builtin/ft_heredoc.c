/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:26:05 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:26:29 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "rules.h"

char	*random_here(void)
{
	static int	nb = 0;
	char		*ret;
	char		*number;

	number = ft_itoa(nb++);
	ret = ft_strjoin("here_doc", number);
	ft_free(number);
	return (ret);
}

void	read_input(t_rules *rules)
{
	char	*line;

	if (dup2(rules->data->save_stdin, STDIN_FILENO) == -1)
		perror("dup2");
	while (1)
	{
		line = readline("> ");
		if (!line)
			ft_put_error(rules->data->prog_name, "EOF are encounter");
		if (!line || !ft_strcmp(line, rules->arg))
			break ;
		ft_putendl_fd(line, rules->data->fd_in);
	}
	close(rules->data->fd_in);
	if (line)
		free(line);
}

void	ft_heredoc2(t_rules *rules, char *name)
{
	ft_free(name);
	if (signal(SIGINT, heredoc_prompt_signal) == SIG_ERR)
		perror(rules->data->prog_name);
	read_input(rules);
	g_exit_status >>= 8;
	exit(g_exit_status);
}

void	ft_heredoc(t_rules *rules)
{
	char	*name;
	pid_t	pid;

	name = random_here();
	if (exec_father_signals())
		perror(rules->data->prog_name);
	rules->data->fd_in = open(name, O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (rules->data->fd_in == -1)
		perror("here_doc");
	pid = fork();
	if (pid == 0)
		ft_heredoc2(rules, name);
	waitpid(pid, &g_exit_status, 0);
	g_exit_status = WEXITSTATUS(g_exit_status);
	if (g_exit_status == 130)
		rules->data->op_err = 2;
	close(rules->data->fd_in);
	rules->data->fd_in = open(name, O_RDONLY);
	dup2(rules->data->fd_in, STDIN_FILENO);
	close(rules->data->fd_in);
	if (unlink(name) == -1)
		perror("unlink");
	ft_free(name);
}
