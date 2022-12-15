#include <stdlib.h>
#include <limits.h>
#include "rules.h"
#include "execute.h"

int ft_best_atoi(char *s, int *ret)
{
	int 			i;
	int 			neg;
	unsigned long	val;

	i = 0;
	val = 0;
	neg = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		neg -= (s[i] - '+');
		i++;
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i])
			|| (val * 10 + (s[i] - '0') > LONG_MAX && neg == 1)
			|| (val * 10 + (s[i] - '0') > (unsigned long)LONG_MAX + 1
			&& neg == -1))
			return (-1);
		val = val * 10 + (s[i++] - '0');
	}
	*ret = (val * neg) % 256;
	return (1);
}

int	ft_make_exit(char **args)
{
	int	exit_status;

	if (*args && *(args + 1))
	{
		// TODO error too many argument
		return (1);
	}
	ft_putendl_fd("exit", 2);
	exit_status = g_exit_status;
	if (*args)
	{
		if (ft_best_atoi(*args, &exit_status) == -1)
		{
			// TODO error argument are not a number
			exit_status = 2;
		}
	}
	exit(exit_status);
}

int	ft_my_exit(const char *name, char * const *args, char * const *env)
{
	(void)name;
	(void)env;
	exit(ft_make_exit((char **)args + 1));
}


void	ft_exit(t_rules *rules)
{
	if (rules->data->pipe != -1)
		ft_execute(rules->data, rules->arg, ft_my_exit);
	else
		g_exit_status = ft_make_exit((char **)rules->arg + 1);
}