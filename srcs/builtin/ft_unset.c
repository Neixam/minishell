#include <stdlib.h>
#include "rules.h"
#include "execute.h"

int	ft_make_unset(t_hash_set *env, char **var_names)
{
	char	*reject;

	while (*var_names)
	{
		reject = ft_remove_element(env, *(var_names++), ft_var_cmp);
		if (reject)
			ft_free(reject);
	}
	return (0);
}

int	ft_my_unset(const char *name, char * const *args, char * const *env)
{
	t_hash_set *my_env;

	(void)name;
	my_env = init_env((char **)env);
	exit(ft_make_unset(my_env, (char **)args + 1));
}

void	ft_unset(t_rules *rules)
{
	if (rules->data->pipe != -1)
		ft_execute(rules->data, rules->arg, ft_my_unset);
	else
		g_exit_status = ft_make_unset(rules->data->env,
		(char **)rules->arg + 1);
}