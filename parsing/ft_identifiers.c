/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <mafissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:17:43 by slepetit          #+#    #+#             */
/*   Updated: 2023/11/08 19:44:25 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_rgb(t_parse *parse, char **id, char **rgb, char *line)
{
	if (!ft_strcmp(id[0], "F"))
	{
		if (parse->floor)
		{
			ft_free_tab(rgb);
			ft_error_identifiers(parse, id, line);
		}
		parse->floor = 1;
		parse->f[0] = ft_atoi(rgb[0]);
		parse->f[1] = ft_atoi(rgb[1]);
		parse->f[2] = ft_atoi(rgb[2]);
	}
	else if (!ft_strcmp(id[0], "C"))
	{
		if (parse->ceiling)
		{
			ft_free_tab(rgb);
			ft_error_identifiers(parse, id, line);
		}
		parse->ceiling = 1;
		parse->c[0] = ft_atoi(rgb[0]);
		parse->c[1] = ft_atoi(rgb[1]);
		parse->c[2] = ft_atoi(rgb[2]);
	}
	ft_free_tab(rgb);
}

void	ft_info(t_parse *parse, char **id, char *line)
{
	char	**rgb;
	int		i;
	int		j;

	i = -1;
	rgb = ft_fill_rgb(parse, id, line);
	while (rgb[++i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
			{
				ft_free_tab(rgb);
				ft_error_identifiers(parse, id, line);
			}
			j++;
		}
	}
	ft_rgb(parse, id, rgb, line);
}

void	ft_id(t_parse *parse, char **id, char *line)
{
	if (!ft_strcmp(id[0], "NO") && ft_is_fill(parse, parse->no, id, line))
		parse->no = ft_strdup(id[1]);
	else if (!ft_strcmp(id[0], "SO") && ft_is_fill(parse, parse->so, id, line))
		parse->so = ft_strdup(id[1]);
	else if (!ft_strcmp(id[0], "WE") && ft_is_fill(parse, parse->we, id, line))
		parse->we = ft_strdup(id[1]);
	else if (!ft_strcmp(id[0], "EA") && ft_is_fill(parse, parse->ea, id, line))
		parse->ea = ft_strdup(id[1]);
	else if (!ft_strcmp(id[0], "F"))
		ft_info(parse, id, line);
	else if (!ft_strcmp(id[0], "C"))
		ft_info(parse, id, line);
	else if (*line != '\n' && !ft_spaces(line))
		ft_error_identifiers(parse, id, line);
}

void	ft_check_line(t_parse *parse, char *line)
{
	char	**id;

	id = ft_split(line, 32);
	while (ft_tablen(id) > 2)
		id = ft_split_all(id);
	if (ft_tablen(id) != 2 && ft_strlen(line) == 1 && *line != '\n')
		ft_error_identifiers(parse, id, line);
	ft_id(parse, id, line);
	ft_free_tab(id);
}

void	ft_identifiers(t_parse *parse, char *file)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_check_line(parse, line);
		if (ft_all_identifiers(parse))
			break ;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	ft_check_identifiers(parse);
	parse->limit = i;
	close(fd);
}
