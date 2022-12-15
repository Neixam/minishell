/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:07:56 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 18:28:26 by ambouren         ###   ########.fr       */
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
#include <stdbool.h>
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
		printf("exit\n");
		exit(g_exit_status);
	}
	ft_garb_add(buf);
	ret = parsing(buf, data);
	if (ret)
	{
		printf("%s: parse error\n", data->prog_name);
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
	data->line++;
}
/*
void	printTreeAux(t_tree *node)
{
	static bool rightmost[128];
	static int depth = 0;
	t_rules	*value;

	if (!node)
	{
		depth = 0;
		for (int i = 0; i < 128; i++)
			rightmost[i] = false;
	}
	for (int i = 1; i < depth; i++)
	{
		printf(rightmost[i] ? "    " : "\u2502   ");
	}
	if (depth > 0)
	{
		printf(rightmost[depth] ? "\u2514\u2500\u2500 " : "\u251c\u2500\u2500 ");
	}
	value = (t_rules *)node->content;
	if (value->token <= ENV && value->token > CMD)
	{
		for (char **av = (char **)value->arg; *av; av++)
			printf("'%s'%c", *av, (*(av + 1)) ? ' ' : '\n');
	}
	else if (value->token >= APPEND
			 && value->token <= REDIR_IN)
		printf("%s '%s'\n", (value->token == REDIR_OUT) ? ">" :
							(value->token == REDIR_IN) ? "<" :
							(value->token == APPEND) ? ">>" : "<<",
			   (char *)value->arg);
	else
		printf("'%s'\n", (char *)value->arg);
	depth++;
	for (t_tree *child = node->child; child != 0; child = child->bro)
	{
		rightmost[depth] = (child->bro) ? false : true;
		printTreeAux(child);
	}
	depth--;
}
*/
int ft_retrieve_status(int exit_status, int *first)
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
	int 	exit_status;
	int 	first;

	/*printTreeAux(data->abstract_tree);*/
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
		prompt_signals();
		if (!ft_retrieve_prompt(data))
			list_exec(data);
	}
}
