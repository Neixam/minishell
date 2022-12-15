#include <stdlib.h>
#include "rules.h"
#include "execute.h"

int	ft_make_export(t_hash_set *env, char **args)
{
	char	**split_arg;
	char	*name;
	char 	*things;

	while (*args)
	{
		things = ft_strchr(*args, '=');
		if (things)
		{
			split_arg = ft_split(*args, '=');
			name = split_arg[0];
			if (!ft_is_varname(name))
			{
				ft_free_tab(split_arg);
				return (1); // TODO error export
			}
			set_var(name, things + 1, env);
			ft_free_tab(split_arg);
		}
		args++;
	}
	return (0);
}

int	ft_my_export(const char *name, char * const *args, char * const *env)
{
	t_hash_set *my_env;

	(void)name;
	my_env = init_env((char **)env);
	exit(ft_make_export(my_env, (char **)args + 1));
}

void	ft_export(t_rules *rules)
{
	if (rules->data->pipe != -1)
		ft_execute(rules->data, rules->arg, ft_my_export);
	else
		g_exit_status = ft_make_export(rules->data->env,
									  (char **)rules->arg + 1);
}