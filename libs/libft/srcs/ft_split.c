/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:30:30 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 13:57:51 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len++;
			while (*s && *s != c)
				s++;
		}
		if (*s)
			s++;
	}
	return (len);
}

static char	*ft_recup_word(char **s, char c)
{
	int		len_word;
	char	*ret;

	len_word = 0;
	while (*(*s + len_word) && *(*s + len_word) != c)
		len_word++;
	ret = ft_substr(*s, 0, len_word);
	*s += len_word;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		i_word;
	char	**ret;

	if (!s)
		return (0);
	ret = (char **)ft_malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	i_word = 0;
	while (*s)
	{
		if (*s != c)
			ret[i_word++] = ft_recup_word((char **)&s, c);
		if (*s)
			s++;
	}
	ret[i_word] = 0;
	return (ret);
}
