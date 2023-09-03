/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:08:51 by slepetit          #+#    #+#             */
/*   Updated: 2023/09/03 19:31:47 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	Rajoute a la map temporaire, la map initiale
	A l'interieur des lignes de 1 et d'espaces d'ou le +2
*/

char	**ft_fill_tmp(char **tmp, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			tmp[i + 2][j + 2] = map[i][j];
			j++;
		}
		i++;
	}
	return (tmp);
}

/*
	Creer une map temporaire et l'entoure de 1 et d'espace a linterieur
*/

char	**ft_set_tmp(int height, int width)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = ft_calloc(sizeof(char *), height + 1);
	if (!tmp)
		return (NULL);
	while (i < height)
	{
		j = 0;
		tmp[i] = ft_calloc(sizeof(char), width + 1);
		while (j < width)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				tmp[i][j] = '1';
			else
				tmp[i][j] = 32;
			j++;
		}
		i++;
	}
	return (tmp);
}

/*
	Regarde maintenant si chaque espace est entoure soit d'un espace soit d'un 1
	Si ce n'est pas le cas, c'est que la map n'est pas ferme et\ou mauvais composants
*/

int	ft_map_close(char **tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == 32)
			{
				if (tmp[i + 1][j] != '1' && tmp[i + 1][j] != 32)
					return (1);
				if (tmp[i - 1][j] != '1' && tmp[i - 1][j] != 32)
					return (1);
				if (tmp[i][j + 1] != '1' && tmp[i][j + 1] != 32)
					return (1);
				if (tmp[i][j - 1] != '1' && tmp[i][j - 1] != 32)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
	Regarde si les composants sont bons
*/

void	ft_map_components(t_parse *parse, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_check_components(parse, map[i][j]);
			j++;
		}
		i++;
	}
}

/*
	ft_tablen(tab) + 4 PORQUE ??
	Pour entourer une map de 1 et d'espaces
	EXEMPLE (map mauvaise)
	11111111
	1      1
	1 1111 1
	1 10N1 1
	1 1001 1
	1 1101 1
	1      1
	11111111
*/

void	ft_map(t_parse *parse)
{
	char	**tmp;

	tmp = ft_set_tmp(ft_tablen(parse->map) + 4, ft_longer_line(parse->map) + 4);
	tmp = ft_fill_tmp(tmp, parse->map);
	ft_map_components(parse, parse->map);
	if (ft_map_close(tmp))
		ft_error_map(parse, tmp);
	ft_free_tab(tmp);
}
