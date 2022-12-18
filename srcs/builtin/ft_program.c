/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:23:07 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:23:37 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rules.h"
#include "execute.h"

void	ft_program(t_rules *rules)
{
	ft_execute(rules->data, rules->arg, execve);
}

void	ft_cmd(t_rules *rules)
{
	if (rules->data->pipe != -1)
		rules->data->pipe++;
}
