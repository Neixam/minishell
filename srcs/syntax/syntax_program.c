#include "syntax.h"
#include "token.h"
#include "rules.h"
#include "garbage.h"

int	ft_count_arg(t_list *cmd)
{
	int			ret;
	t_token		*token;

	ret = 0;
	while (cmd)
	{
		ft_skip_space(&cmd);
		if (!cmd)
			return (ret);
		token = (t_token *)cmd->content;
		if (token->name != LITERAL)
			return (ret);
		ret++;
		cmd = cmd->next;
	}
	return (ret);
}

char	**ft_argument_check(t_list **cmd)
{
	char	**ret;
	int		i;

	ret = (char **)ft_malloc(sizeof(char *) * (ft_count_arg(*cmd) + 1));
	i = 0;
	while (*cmd)
	{
		ft_skip_space(cmd);
		if (!*cmd || ft_get_name((*cmd)->content) != LITERAL)
			break ;
		ret[i++] = ft_strdup(((t_token *)(*cmd)->content)->value);
		*cmd = (*cmd)->next;
	}
	ret[i] = 0;
	return (ret);
}

t_tree	*ft_program_check(t_data *data, t_list **cmd)
{
	t_token	*token;
	ft_skip_space(cmd);
	if (!*cmd)
		return (0);
	token = (*cmd)->content;
	if (ft_get_name(token) != LITERAL)
		return (0);
	return (ft_new_node(
			ft_new_rules(data,
						 ft_literal_value(token),
						 ft_argument_check(cmd))));
}