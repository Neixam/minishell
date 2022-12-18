/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:22:06 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 16:24:02 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

t_applied	ft_get_apply(t_token_name name)
{
	static t_applied	applies[] = {
		ft_cmd,
		ft_program,
		ft_echo,
		ft_cd,
		ft_pwd,
		ft_export,
		ft_exit,
		ft_unset,
		ft_env,
		ft_append,
		ft_heredoc,
		ft_redirout,
		ft_redirin,
		ft_pipe
	};

	return (applies[name]);
}

t_token_name	ft_literal_value(t_token *token)
{
	static char		*rules[] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"exit",
		"unset",
		"env",
		NULL
	};
	t_token_name	name;

	name = -1;
	while (rules[++name])
		if (!ft_strcmp(rules[name], token->value))
			return (name + ECHO);
	return (PROGRAM);
}

void	ft_free_rules(void *a)
{
	t_rules	*rules;

	rules = (t_rules *)a;
	if (rules->token <= ENV)
		ft_free_tab(rules->arg);
	else if (rules->token < PIPE)
		ft_free(rules->arg);
	ft_free(rules);
}

t_rules	*ft_new_rules(t_data *data, t_token_name token, void *arg)
{
	t_rules	*ret;

	ret = (t_rules *)ft_malloc(sizeof(t_rules));
	ret->token = token;
	ret->apply = ft_get_apply(token);
	ret->data = data;
	ret->arg = arg;
	return (ret);
}
