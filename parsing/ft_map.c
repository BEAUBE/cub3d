/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:08:51 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/28 03:45:47 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	ft_map(t_parse *parse)
{
	char	**tmp;

	tmp = ft_set_tmp(ft_tablen(parse->map) + 4, ft_longer_line(parse->map) + 4);
	tmp = ft_fill_tmp(tmp, parse->map);
	if (ft_map_close(tmp))
		ft_error_map(parse, tmp);
	ft_free_tab(tmp);
	ft_map_components(parse, parse->map);
}
