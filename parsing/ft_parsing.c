/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:36:09 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/10 16:21:44 by slepetit         ###   ########.fr       */
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
	close(fd);
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

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	check_nbr_element(char *line)
{
	char **tab;
	static int	nbr_infos;

	tab = ft_split(line, ' ');
	if (tab[0][0] == '\n')
	{
		ft_free_tab(tab);
		return (1);
	}
	if (ft_tablen(tab) != 3)
	{
		ft_free_tab(tab);
		return (0);
	}
	else
		nbr_infos += 1;
	if (nbr_infos == 7)
	{
		ft_free_tab(tab);
		return (0);
	}
	if (nbr_infos < 7 && ft_isdigit(tab[0][0]))
	{
		ft_free_tab(tab);
		return (0);
	}
	return (1);
}

int	add_to_data(t_data *data, char *line)
{
	check_nbr_element(line);
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
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_printf("%s", line);
	}
	free(line);
	close(fd);
}

void	ft_parsing(t_data *data, char *file, int ac)
{
	ft_filename(file, ac);
	ft_gnl(data, file);
	ft_map(data, data->map);
	// ft_collect_infos(file, data);
}
