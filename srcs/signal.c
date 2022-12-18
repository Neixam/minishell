/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:33:46 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:21:23 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <readline/readline.h>
#include <unistd.h>
#include "minishell.h"

void	readline_restart(int sign)
{
	(void)sign;
	g_exit_status = 130;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	prompt_signals(void)
{
	if (signal(SIGINT, readline_restart) == SIG_ERR)
		return (1);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (1);
	return (0);
}

int	exec_father_signals(void)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		return (1);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (1);
	return (0);
}

int	exec_child_signals(void)
{
	if (signal(SIGINT, SIG_DFL) == SIG_ERR)
		return (1);
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		return (1);
	return (0);
}

void	heredoc_prompt_signal(int sign)
{
	(void)sign;
	g_exit_status |= (130 << 8);
	close(STDIN_FILENO);
}
