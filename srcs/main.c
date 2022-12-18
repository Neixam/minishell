/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:18:47 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/28 12:41:31 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	g_exit_status = 0;

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac > 1)
	{
		printf("%s: too many argument\n", *av);
		return (1);
	}
	init_minishell(&data, *av, env);
	start_minishell(&data);
	return (0);
}
