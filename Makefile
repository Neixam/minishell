# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambouren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 15:05:48 by ambouren          #+#    #+#              #
#    Updated: 2022/12/18 16:28:54 by ambouren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc

CFLAGS  =	-Wall -Wextra -Werror -g
IFLAGS	=	-I includes/ -I libs/libft/includes/
LDFLAGS	=	-L libs/ -lft -lreadline
EXEC	=	minishell

INC_PATH=	includes/
DEP_PATH=	deps/
OBJ_PATH=	objs/
LIB_PATH=	libs/
SRC_PATH=	$(shell find srcs -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))
vpath %.a $(LIB_PATH)
LIB		=	libft.a
SRC		=	main.c \
			minishell.c \
			parsing.c \
			signal.c \
			environnemnt.c \
			var.c \
			syntax.c \
			syntax_program.c \
			syntax_redir.c \
			token.c \
			token2.c \
			rules.c \
			ft_cd.c \
			ft_echo.c \
			ft_env.c \
			ft_exit.c \
			ft_export.c \
			ft_heredoc.c \
			ft_pipe.c \
			ft_program.c \
			ft_pwd.c \
			ft_redirect.c \
			ft_unset.c \
			error.c \
			dispatch.c \
			ft_execute.c \
			ft_retrieve.c \
			data.c
DEP		=	$(addprefix $(DEP_PATH), $(SRC:.c=.d))
OBJ		=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))

#	Compilation
all		:	$(EXEC)

$(EXEC)			:	$(addprefix $(LIB_PATH), $(LIB)) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.a				:
	@make -C $(@:.a=) install

$(OBJ_PATH)%.o	:	%.c
	@mkdir -p $(OBJ_PATH) $(DEP_PATH)
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS) -MMD
	@mv $(@:.o=.d) $(DEP_PATH)

-include $(DEP)

#	Rule
clean	:
	rm -rf $(OBJ_PATH)
	rm -rf $(DEP_PATH)

fclean	:	clean $(foreach lib, $(LIB), $(LIB_PATH)$(lib:.a=)_fclean)
	rm -rf $(EXEC)
	rm -rf $(addprefix $(LIB_PATH), $(LIB))

%_fclean		:
	@make -C $(subst _, , $@)
	
re		:	fclean all

.PHONY	:	all clean fclean re
