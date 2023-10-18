/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_game_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:10:57 by slepetit          #+#    #+#             */
/*   Updated: 2023/10/18 20:11:32 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_fill_walls(char **tmp, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 32)
				tmp[i + 1][j + 1] = '1';
			else
				tmp[i + 1][j + 1] = map[i][j];
			j++;
		}
		i++;
	}
	return (tmp);
}

char	**ft_set_walls(int height, int width)
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
			tmp[i][j] = '1';
			j++;
		}
		i++;
	}
	return (tmp);
}
