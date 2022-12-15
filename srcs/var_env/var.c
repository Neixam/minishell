#include "minishell.h"

int	ft_is_varname(char *name)
{
	int i;

	i = -1;
	while (name[++i])
	{
		if (!(ft_isalpha(name[i])
			|| (ft_isdigit(name[i]) && i != 0)
			|| name[i] == '_'))
			return (0);
	}
	return (1);
}

void	set_var(char *name, char *things, t_hash_set *env)
{
	char	*last;
	char	*tmp;

	last = (char *)ft_remove_element(env, name, ft_var_cmp);
	if (last)
		ft_free(last);
	tmp = ft_strjoin(name, "=");
	ft_put_element(env, ft_strjoin(tmp, things));
	ft_free(tmp);
}

char	*get_var(t_hash_set *env, char *name)
{
	char	*total_def;

	total_def = ft_get_elem(env, name, ft_var_cmp);
	if (!total_def)
	{
		if (!ft_strcmp(name, "?"))
			return (ft_itoa(g_exit_status));
		return (ft_strdup(""));
	}
	return (ft_strdup(ft_strchr(total_def, '=') + 1));
}