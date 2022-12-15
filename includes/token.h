/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:37:51 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 18:28:29 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_token_name
{
	CMD,			/* 0  */
	PROGRAM,		/* 1  */
	ECHO,			/* 2  */
	CD,				/* 3  */
	PWD,			/* 4  */
	EXPORT,			/* 5  */
	EXIT,			/* 6  */
	UNSET,			/* 7  */
	ENV,			/* 8  */
	APPEND,			/* 9  */
	HEREDOC,		/* 10 */
	REDIR_OUT,		/* 11 */
	REDIR_IN,		/* 12 */
	PIPE,			/* 13 */
	VARIABLE,		/* 14 */
	SIMPLE_QUOTE,	/* 15 */
	DOUBLE_QUOTE,	/* 16 */
	WHITESPACE,		/* 17 */
	LITERAL			/* 18 */
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
