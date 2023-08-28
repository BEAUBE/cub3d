/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:13:19 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/28 03:13:57 by slepetit         ###   ########.fr       */
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

t_parse	*ft_get_map(t_parse *parse, char *file)
{
	char	*s;
	char	*tmp;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	parse->map = ft_calloc(sizeof(char), (ft_get_lines(file) - parse->limit) + 1);
	s = ft_calloc(sizeof(char), 1);
	*s = 0;
	i = 1;
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (i < parse->limit)
		{
			free(tmp);
			tmp = get_next_line(fd);
			i++;
			continue ;
		}
		if (*tmp == '\n')
			ft_error_newline(parse, tmp, s);
		s = ft_strjoin(s, tmp);
		ft_printf("%s", tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	parse->map = ft_split(s, '\n');
	free(s);
	close(fd);
	return (parse);
}

void	ft_pass_newline(char *tmp, int fd, int *i)
{
	free(tmp);
	tmp = get_next_line(fd);
	while (tmp && *tmp == '\n')
	{
		(*i) += 1;
		free(tmp);
		tmp = get_next_line(fd);
	}
}

void	ft_map_limits(t_parse *parse, char *file)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (*tmp != '\n')
			parse->limit++;
		i++;
		if (parse->limit == 6)
		{
			ft_pass_newline(tmp, fd, &i);
			break ;
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	parse->limit = i - 1;
	free(tmp);
	close(fd);
}