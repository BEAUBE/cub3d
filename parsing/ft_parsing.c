/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:36:09 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/09 14:56:23 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_gnl_lines(char *file)
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

t_data	*ft_gnl(t_data *data, char *file)
{
	char	*s;
	char	*tmp;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (NULL);
	data->map = ft_calloc(sizeof(char), ft_gnl_lines(file) + 1);
	s = ft_calloc(sizeof(char), 1);
	*s = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		s = ft_strjoin(s, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	data->map = ft_split(s, '\n');
	free(s);
	return (data);
}

void	ft_filename(char *file, int ac)
{
	int	i;

	i = ft_strlen(file) - 4;
	if (ac < 2)
	{
		ft_putstr_fd("Cub3D needs a map\n", 2);
		exit(2);
	}
	if (i < 0 || ft_strcmp(&file[i], ".cub"))
	{
		ft_putstr_fd("The map file must have the extension .cub\n", 2);
		exit(2);
	}
	if (open(file, F_OK, X_OK) < 0)
	{
		perror(file);
		exit(2);
	}
}

int	is_valid_element(char *line)
{
	int i;
	
	skip_spaces(line, &i);
	if (line[i] && (ft_strncmp(&line[i], "NO ", 3) || ft_strncmp(&line[i], "SO ", 3) ||
		ft_strncmp(&line[i], "EA ", 3) || ft_strncmp(&line[i], "WE ", 3)))
	{
		i += 3;
		skip_spaces(line, &i);
		while (line[i] && line[i] != ' ')
			i++;
	}	
	else
		return (0);
	if (line[i])
		skip_spaces(line, &i);
	return (1);
}

int	add_to_data(t_data *data, char *line)
{
	int i;

	i = 0;
	if (!is_valid_element(line))//' ' direction ' ' path ' ' // pas plus 
	return (0);
}

void	ft_collect_infos(char *file, t_data *data)
{
	char *line;
	int i;
	int fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		add_to_data(data, line);
		line = get_next_line(fd);
	}
}

void	ft_parsing(t_data *data, char *file, int ac)
{
	ft_filename(file, ac);
//	ft_gnl(data, file);
	ft_collect_infos(file, data);
}
