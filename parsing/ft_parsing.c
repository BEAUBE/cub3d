/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:36:09 by slepetit          #+#    #+#             */
/*   Updated: 2023/09/03 18:53:51 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	Verifie si le fichier existe ou si les droits sont ok
	Verifie que le fichier n'est pas vide
*/

void	ft_file(char *file)
{
	int	fd;

	if (open(file, F_OK, X_OK) < 0)
	{
		perror(file);
		exit(2);
	}
	fd = open(file, O_RDONLY);
	if (get_next_line(fd) == NULL)
	{
		ft_putstr_fd("Error\nEmpty file\n", 2);
		close(fd);
		exit(2);
	}
	close(fd);
}

/*
	Verifie si il y a un fichier
	Verifie si l'extension est bonne (.cub seul fonctionne)
*/

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
		ft_map_limits(main->parse, file);
		ft_get_map(main->parse, file);
		ft_map(main->parse);
		ft_fill_game(main, main->parse);
	}
	return (main);
}
