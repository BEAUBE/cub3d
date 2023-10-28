/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:13:19 by slepetit          #+#    #+#             */
/*   Updated: 2023/10/28 23:35:58 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_get_lines(char *file)
{
	int	lines;
	int	fd;

	lines = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd) != NULL)
		lines++;
	close(fd);
	return (lines);
}

char	*ft_pass_newline(int fd, char *tmp, int *i)
{
	free(tmp);
	tmp = get_next_line(fd);
	while (tmp && *tmp == '\n')
	{
		*i += 1;
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (tmp);
}

char	*ft_start_map(int fd, char *tmp, int *i, int limit)
{
	while (*i <= limit)
	{
		if (*i == limit)
		{
			tmp = ft_pass_newline(fd, tmp, i);
			break ;
		}
		free(tmp);
		tmp = get_next_line(fd);
		*i += 1;
	}
	*i += 1;
	return (tmp);
}

t_parse	*ft_get_map(t_parse *parse, char *file)
{
	char	*s;
	char	*tmp;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	s = ft_calloc(sizeof(char), 1);
	if (!s)
		return (NULL);
	i = 1;
	tmp = get_next_line(fd);
	while (tmp)
	{
		tmp = ft_start_map(fd, tmp, &i, parse->limit);
		if (*tmp == '\n')
			ft_error_newline(parse, tmp, s);
		s = ft_strjoin(s, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	parse->map = ft_split(s, '\n');
	free(s);
	close(fd);
	return (parse);
}
