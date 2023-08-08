/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:13:38 by slepetit          #+#    #+#             */
/*   Updated: 2023/01/01 15:29:36 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_gnl(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!str || !len)
		return (NULL);
	if (start >= ft_strlen(str))
		return (NULL);
	if (len >= ft_strlen(str))
		len = ft_strlen(str) - start;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (str[start] && len--)
		dest[i++] = str[start++];
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dest;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = 0;
	free(s1);
	return (dest);
}

size_t	ft_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (i);
}

char	*ft_fill(char *str, int fd)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	*buff = 0;
	while (i && !ft_strchr(str, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = 0;
		str = ft_strjoin_gnl(str, buff);
		if (!str)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*str;
	char		*line;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	*str = 0;
	if (read(fd, str, 0) == -1 || fd < 0 || BUFFER_SIZE < 1)
		return (free(str), NULL);
	if (!save)
	{
		save = malloc(sizeof(char));
		if (!save)
			return (NULL);
		*save = 0;
	}
	str = ft_strjoin_gnl(str, save);
	free(save);
	str = ft_fill(str, fd);
	save = ft_substr_gnl(str, ft_nl(str), ft_strlen(str) - ft_nl(str) + 1);
	line = ft_substr_gnl(str, 0, ft_nl(str));
	free(str);
	return (line);
}
