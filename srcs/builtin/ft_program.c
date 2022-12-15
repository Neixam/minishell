#include <unistd.h>
#include "rules.h"
#include "execute.h"

void	ft_program(t_rules *rules)
{
	ft_execute(rules->data, rules->arg, execve);
}

void	ft_cmd(t_rules *rules)
{
	if (rules->data->pipe != -1)
		rules->data->pipe++;
}