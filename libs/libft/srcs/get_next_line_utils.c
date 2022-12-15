/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:10:00 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 13:57:36 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	ft_strclen(char *s, char c)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (c == '\n' && c == s[len])
		return (len + 1);
	return (len);
}

int	ft_decal_buff(char *buffer, int decal)
{
	int	i;
	int	len;
	int	ret;

	ret = buffer[decal - 1];
	len = ft_strclen(&buffer[decal], 0);
	i = -1;
	while (++i <= len)
		buffer[i] = buffer[i + decal];
	return (ret == '\n');
}

int	ft_recup_line(char **line, char *buffer)
{
	char	*ant_line;
	int		len;
	int		i;
	int		j;

	len = ft_strclen(*line, 0) + ft_strclen(buffer, '\n');
	ant_line = *line;
	*line = (char *)ft_malloc(sizeof(char) * (len + 1));
	i = 0;
	while (ant_line && ant_line[i])
	{
		(*line)[i] = ant_line[i];
		i++;
	}
	if (ant_line)
		ft_free(ant_line);
	j = 0;
	while (i < len)
		(*line)[i++] = buffer[j++];
	(*line)[i] = 0;
	return (ft_decal_buff(buffer, j));
}

char	*ft_panoic(char *line)
{
	if (line)
		ft_free(line);
	return (NULL);
}
