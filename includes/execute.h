#ifndef EXECUTE_H
# define EXECUTE_H
# include "minishell.h"

typedef int (*t_exec)(const char *, char * const [], char * const []);

void	ft_execute(t_data *data, char **args, t_exec exec);
void	dispatch(void *cnt);

#endif
