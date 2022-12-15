#include "libft.h"

void	*ft_collect(t_hash_set *set, size_t size, void (*collector)(void *,
			void *))
{
	int i;
	t_list *entry;
	void *ret;

	i = -1;
	ret = ft_malloc((set->size + 1) * size);
	while (++i < set->capacity)
	{
		entry = set->entries[i];
		while (entry)
		{
			collector(ret, entry->content);
			entry = entry->next;
		}
	}
	return (ret);
}