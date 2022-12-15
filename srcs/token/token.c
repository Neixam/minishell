#include "token.h"
#include "libft.h"

t_token_name	ft_type_token(char c)
{
	static t_token	tokens[] =
			{
					{ REDIR_OUT, ">" },
					{ REDIR_IN, "<" },
					{ PIPE, "|" },
					{ VARIABLE, "$" },
					{ SIMPLE_QUOTE, "'" },
					{ DOUBLE_QUOTE, "\"" },
					{ WHITESPACE, " " }
			};
	t_token_name	ret;

	ret = 0;
	while (ret + REDIR_OUT < LITERAL)
	{
		if (c == *tokens[ret].value)
			return (ret + REDIR_OUT);
		ret++;
	}
	return (ret + REDIR_OUT);
}

t_token *ft_new_token(char *value, t_token_name name)
{
	t_token	*ret;

	ret = (t_token *)ft_malloc(sizeof(t_token));
	ret->value = value;
	ret->name = name;
	return (ret);
}

void	ft_free_token(void *token)
{
	ft_free(((t_token *)token)->value);
	ft_free(token);
}

t_token_name	ft_get_name(void *t)
{
	return (((t_token *)t)->name);
}

int	ft_token_cmp(void *t1, void *t2)
{
	if (ft_get_name(t1) == APPEND || ft_get_name(t1) == HEREDOC)
		return (1);
	return ((int)ft_get_name(t1) - (int)ft_get_name(t2));
}

void	ft_fuse_token(t_token *t1, t_token *t2)
{
	char	*ptr;

	ptr = t1->value;
	if (t1->name == REDIR_OUT)
		t1->name = APPEND;
	if (t1->name == REDIR_IN)
		t1->name = HEREDOC;
	t1->value = ft_strjoin(t1->value, t2->value);
	ft_free(ptr);
}