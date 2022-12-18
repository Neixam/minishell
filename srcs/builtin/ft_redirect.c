/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:30:16 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:30:43 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "rules.h"

void	ft_redirout(t_rules *rules)
{
	rules->data->fd_out = open(rules->arg, O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (rules->data->fd_out == -1)
	{
		g_exit_status = 1;
		rules->data->op_err = 1;
		ft_putstr_fd("minishell: ", 2);
		perror(rules->arg);
		return ;
	}
	if (dup2(rules->data->fd_out, STDOUT_FILENO) == -1)
		perror(rules->data->prog_name);
	close(rules->data->fd_out);
}

void	ft_redirin(t_rules *rules)
{
	rules->data->fd_in = open(rules->arg, O_RDONLY);
	if (rules->data->fd_in == -1)
	{
		g_exit_status = 1;
		rules->data->op_err = 1;
		ft_putstr_fd("minishell: ", 2);
		perror(rules->arg);
		return ;
	}
	dup2(rules->data->fd_in, STDIN_FILENO);
	close(rules->data->fd_in);
}

void	ft_append(t_rules *rules)
{
	rules->data->fd_out = open(rules->arg, O_WRONLY | O_APPEND | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (rules->data->fd_out == -1)
	{
		g_exit_status = 1;
		rules->data->op_err = 1;
		ft_putstr_fd("minishell: ", 2);
		perror(rules->arg);
		return ;
	}
	if (dup2(rules->data->fd_out, STDOUT_FILENO))
		perror(rules->data->prog_name);
	close(rules->data->fd_out);
}
