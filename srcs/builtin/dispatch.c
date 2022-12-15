#include <unistd.h>
#include <stdio.h>
#include "rules.h"

void	dispatch(void *cnt)
{
	t_rules	*rules;

	rules = cnt;
	if (!rules->data->op_err)
		return (rules->apply(rules));
	if (rules->data->op_err == 2)
		return ;
	if (rules->token <= ENV && rules->token != CMD)
	{
		if (rules->data->pipe != -1)
			rules->data->pipe++;
		rules->data->fd_out = -1;
		rules->data->fd_in = -1;
		if (rules->data->pipe == 2)
			rules->data->pipe = -1;
		if (dup2(rules->data->save_stdout, STDOUT_FILENO) == -1)
			perror(rules->data->prog_name);
		rules->data->op_err = 0;
	}
}