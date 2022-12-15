#include "libft.h"

void	ft_coll_string(void *a, void *b)
{
	static int i = 0;
	static char **tab = NULL;

	if (!a)
		return ;
	if (a != tab)
	{
		tab = (char **)a;
		i = 0;
	}
	if (!tab)
		tab = (char **)a;
	tab[i++] = ft_strdup(b);
}