/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:52:37 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 16:54:51 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H
# include "token.h"
# include "minishell.h"

typedef struct s_rules
{
	t_token_name	token;
	t_data			*data;
	void			(*apply)(struct s_rules *);
	void			*arg;
}	t_rules;

typedef void (*t_applied)(t_rules *);

t_rules			*ft_new_rules(t_data *data, t_token_name token, void *arg);
t_token_name	ft_literal_value(t_token *token);
void			ft_free_rules(void *a);

void			ft_exit(t_rules *rule);
void			ft_unset(t_rules *rule);
void			ft_pwd(t_rules *rule);
void			ft_cd(t_rules *rule);
void			ft_export(t_rules *rule);
void			ft_program(t_rules *rule);
void			ft_echo(t_rules *rule);
void			ft_redirout(t_rules *rule);
void			ft_redirin(t_rules *rule);
void			ft_append(t_rules *rule);
void			ft_heredoc(t_rules *rule);
void			ft_env(t_rules *rule);
void			ft_pipe(t_rules *rule);
void			ft_cmd(t_rules *rules);

#endif
