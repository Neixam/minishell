#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "rules.h"
#include "execute.h"

int ft_make_cd(t_data *data, char **args)
{
	char	*current_path;

	if (!*args)
	{
		// TODO error not enough argument
		return (1);
	}
	if (*(args + 1))
	{
		// TODO error too many argument
		return (1);
	}
	if (chdir(*args) == -1)
	{
		// TODO error chdir (bad path)
		return (1);
	}
	if (!data)
		return (0);
	current_path = getcwd(0, 0);
	if (!current_path)
	{
		perror("pas bien");
		return (1);
	}
	if (data->initpwd)
	{
		set_var("OLDPWD", data->initpwd, data->env);
		ft_free(data->initpwd);
	}
	data->initpwd = ft_strdup(current_path);
	free(current_path);
	set_var("PWD", data->initpwd, data->env);
	return (0);
}

int	ft_my_cd(const char *name, char * const *args, char * const *env)
{
	(void)name;
	(void)env;
	exit(ft_make_cd(0, (char **)args + 1));
}


void	ft_cd(t_rules *rules)
{
	if (rules->data->pipe != -1)
		ft_execute(rules->data, rules->arg, ft_my_cd);
	else
		g_exit_status = ft_make_cd(rules->data,
									   (char **)rules->arg + 1);
}