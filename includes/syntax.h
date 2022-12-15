#ifndef SYNTAX_H
# define SYNTAX_H
# include "minishell.h"
# include "libft.h"

int		syntax_check(t_data *data);
int		ft_start_check(t_data *data, t_list **cmd, t_tree **tree);
int		ft_pipe_check(t_data *data, t_list **cmd, t_tree **tree);
void	ft_skip_space(t_list **cmd);
t_tree	*ft_program_check(t_data *data, t_list **cmd);
int		ft_redir_check(t_data *data, t_list **cmd, t_tree **tree);

#endif
