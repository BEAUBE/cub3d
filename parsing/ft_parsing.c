/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:36:09 by slepetit          #+#    #+#             */
/*   Updated: 2023/10/28 23:36:22 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_file(char *file)
{
	char	*tmp;
	int		fd;

	if (open(file, F_OK, X_OK) < 0)
	{
		perror(file);
		exit(2);
	}
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
	{
		free(tmp);
		ft_putstr_fd("Error\nEmpty file\n", 2);
		close(fd);
		exit(2);
	}
	free(tmp);
	close(fd);
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
	ft_file(file);
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
		ft_get_map(main->parse, file);
		ft_map(main->parse);
		ft_fill_game(main, main->parse);
	}
	return (main);
}
