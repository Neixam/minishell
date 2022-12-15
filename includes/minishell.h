/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:15:14 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/28 13:03:17 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"

typedef struct s_data
{
	t_hash_set	*env;
	char		*initpwd;
	char		*prog_name;
	char		*prompt;
	int			line;
	int 		fd_out;
	int 		fd_in;
	int 		op_err;
	int 		save_stdout;
	int 		save_stdin;
	int 		pipe;
	t_tree		*abstract_tree;
	t_list		*input;
}	t_data;

extern int	g_exit_status;

void		start_minishell(t_data *data);
int			ft_hashcode_var(char *var);
int			ft_var_cmp(void *elem, void *name);
char		**ft_set_env(t_hash_set *set);
void		set_var(char *name, char *things, t_hash_set *env);
void		init_minishell(t_data *data, char *name, char **env);
int			parsing(char *input, t_data *data);
char		*get_var(t_hash_set *env, char *name);
int			exec_child_signals(void);
int			exec_father_signals(void);
int			prompt_signals(void);
void		heredoc_prompt_signal(int sign);
t_hash_set	*init_env(char **env);
int			ft_is_varname(char *name);

#endif
