/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:36:09 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/25 04:43:41 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_limit(char **map)
{
	int	i;
	int	count;
	int	lim;

	i = 0;
	count = 0;
	lim = 0;
	while (map[i])
	{
		if (count == 6)
			break ;
		if (*map[i] != '\n')
		{
			count++;
			lim++;
		}
		else
			lim++;
	}
	return (lim);
}

char	*ft_get_map(t_parse *parse)
{
	char	**new;
	int		i;
	int		lim;

	i = 0;
	lim = ft_limit(parse->map);
	new = ft_calloc(sizeof(char *), (ft_tablen(parse->map) - lim) + 1);
	if (!new)
		return (NULL);
	while (parse->map[lim])
	{
		new[i] = ft_strdup(parse->map[lim]);
		if (parse->map[lim][0] == '\n')
			ft_error_newline(parse, new);
		ft_printf("%s\n", new[i]);
		lim++;
		i++;
	}
	ft_free_tab(parse->map);
	parse->map = new;
	return (NULL);
}

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

t_parse	*ft_get_file(t_parse *parse, char *file)
{
	char	*s;
	char	*tmp;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	parse->map = ft_calloc(sizeof(char), ft_get_lines(file) + 1);
	s = ft_calloc(sizeof(char), 1);
	*s = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		s = ft_strjoin(s, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	parse->map = ft_split(s, '\n');
	free(s);
	close(fd);
	return (parse);
}

void	ft_filename(char *file, int ac)
{
	int	i;

	i = ft_strlen(file) - 4;
	if (ac < 2)
	{
		ft_putstr_fd("Error\nCub3D needs a map\n", 2);
		exit(2);
	}
	if (i < 0 || ft_strcmp(&file[i], ".cub"))
	{
		ft_putstr_fd("Error\nThe map file must have the extension .cub\n", 2);
		exit(2);
	}
	if (open(file, F_OK, X_OK) < 0)
	{
		perror(file);
		exit(2);
	}
}

t_main	*ft_parsing(t_main *main, char *file, int ac)
{
	ft_filename(file, ac);
	main->parse = ft_calloc(sizeof(t_parse), 1);
	if (!main->parse)
		return (NULL);
	else
	{
		ft_identifiers(main->parse, file);
		// ft_get_file(main->parse, file);
		ft_get_map(main->parse);
		ft_map(main->parse);
		ft_fill_game(main, main->parse);
	}
	return (main);
}
