/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:37:51 by ambouren          #+#    #+#             */
/*   Updated: 2022/12/18 15:17:03 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_token_name
{
	CMD,
	PROGRAM,
	ECHO,
	CD,	
	PWD,
	EXPORT,	
	EXIT,
	UNSET,
	ENV,
	APPEND,	
	HEREDOC,
	REDIR_OUT,
	REDIR_IN,
	PIPE,
	VARIABLE,
	SIMPLE_QUOTE,
	DOUBLE_QUOTE,
	WHITESPACE,
	LITERAL
}	t_token_name;

typedef struct s_token
{
	t_token_name	name;
	char			*value;
}	t_token;

t_token_name	ft_type_token(char c);
t_token_name	ft_get_name(void *t);
void			ft_fuse_token(t_token *t1, t_token *t2);
t_token			*ft_new_token(char *value, t_token_name name);
void			ft_free_token(void *token);
int				ft_token_cmp(void *t1, void *t2);

#endif
