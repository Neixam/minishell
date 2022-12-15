#include <stdlib.h>
#include <stdio.h>
#include "rules.h"
#include "execute.h"

int ft_get_opt(char *first, int *i)
{
	int j;

	if (first && *first != '-')
		return (0);
	j = 0;
	while (first[++j])
	{
		if (first[j] != 'n')
			return (0);
	}
	(*i)++;
	return (1);
}

int	ft_my_echo(const char *name, char * const *args, char * const *env)
{
	int 		opt;
	int 		i;

	(void)name;
	(void)env;
	i = 0;
	opt = ft_get_opt(args[1], &i);
	while (args[++i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
	if (!opt)
		printf("\n");
	exit(0);
}

void	ft_echo(t_rules *rules)
{
	ft_execute(rules->data, rules->arg, ft_my_echo);
}