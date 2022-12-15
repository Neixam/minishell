#include <stdio.h>
#include <stdlib.h>
#include "rules.h"
#include "execute.h"

int	ft_my_pwd(const char *name, char * const *args, char * const *env)
{
	t_hash_set	*tmp_env;
	char		*pwd;

	(void)name;
	(void)args;
	tmp_env = init_env((char**) env);
	pwd = get_var(tmp_env, "PWD");
	if (!pwd)
	{
		// TODO error pwd
		ft_clean_memory();
		exit(-1);
	}
	printf("%s\n", pwd);
	ft_clean_memory();
	exit(0);
}

void	ft_pwd(t_rules *rules)
{
	ft_execute(rules->data, rules->arg, ft_my_pwd);
}