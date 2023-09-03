/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:13:19 by slepetit          #+#    #+#             */
/*   Updated: 2023/09/03 19:16:52 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	Retourne le nombre de ligne du fichier
*/

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

/*
	parse->limit correspond au debut de la map (ex ligne 10)
	si dans la map (apres limit) \n error
*/

t_parse	*ft_get_map(t_parse *parse, char *file)
{
	char	*s;
	char	*tmp;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	s = ft_calloc(sizeof(char), 1);
	*s = 0;
	i = 1;
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (i <= parse->limit)
		{
			free(tmp);
			tmp = get_next_line(fd);
			i++;
			continue ;
		}
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

/*
	cherche le debut de la map
	parse->limit ici m'aide a savoir si j'ai bien passer tous les idenfiants (7)
	i, m'indique le nombre de ligne avant le debut de la map
	je passe apres tous les \n toujours en i++
	je dis que parse->limit = i - 1
	i - 1 car j'ai lu une ligne pour verifier donc je me mets a celle d'avant
*/

void	ft_map_limits(t_parse *parse, char *file)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	i = 0;
	while (tmp)
	{
		if (*tmp != '\n')
			parse->limit++;
		i++;
		if (parse->limit == 7)
		{
			free(tmp);
			tmp = get_next_line(fd);
			while (tmp && *tmp == '\n')
			{
				i++;
				free(tmp);
				tmp = get_next_line(fd);
			}
			break ;
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	parse->limit = i - 1;
	free(tmp);
	close(fd);
}
