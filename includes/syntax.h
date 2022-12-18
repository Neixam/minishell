/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:16:00 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:16:04 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H
# include "minishell.h"
# include "libft.h"
# include "token.h"

int		syntax_check(t_data *data);
int		ft_start_check(t_data *data, t_list **cmd, t_tree **tree);
int		ft_pipe_check(t_data *data, t_list **cmd, t_tree **tree);
void	ft_skip_space(t_list **cmd);
int		ft_program_check(t_data *data, t_list **cmd, t_tree **tree);
int		ft_redir_check(t_data *data, t_list **cmd, t_tree **tree);
int		ft_is_redirect(t_token_name token);
void	ft_retrieve_literal(char *input, int *i, t_list **in);
char	*ft_retrieve_variable(char *input, int *i, t_data *data);
void	ft_retrieve_input(char *input, t_data *data);
int		ft_retrieve_quote(char *input, int *i, t_data *data, t_token_name type);

#endif
