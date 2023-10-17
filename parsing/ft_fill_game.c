/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 05:32:32 by slepetit          #+#    #+#             */
/*   Updated: 2023/10/17 02:16:08 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_cpy_map(char **s, t_game *game)
{
	int		i;

	i = 0;
	game->map = ft_calloc(sizeof(char *), ft_tablen(s) + 1);
	if (!game->map)
		return (NULL);
	while (s[i])
	{
		game->map[i] = ft_strdup(s[i]);
		i++;
	}
	return (game->map);
}

void	ft_orientation(t_game *game, char c)
{
	if (c == 'N')
		game->orientation = 1;
	if (c == 'S')
		game->orientation = 2;
	if (c == 'W')
		game->orientation = 3;
	if (c == 'E')
		game->orientation = 4;
}

int	ft_find_pos(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
					|| map[i][j] == 'W')
			{
				if (game->orientation)
					return (0);
				game->player.posx = j + 0.5;
				game->player.posy = i + 0.5;
				ft_orientation(game, map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (!game->orientation)
		return (0);
	return (1);
}

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

void	ft_fill_game(t_main *main, t_parse *parse)
{
	char	**tmp;

	main->game = ft_calloc(sizeof(t_game), 1);
	if (!ft_find_pos(parse->map, main->game))
		ft_error_pos(parse, main->game);
	tmp = ft_set_walls(ft_tablen(parse->map) + 2, ft_longer_line(parse->map) + 2);
	tmp = ft_fill_walls(tmp, parse->map);
	ft_cpy_map(tmp, main->game);
	main->game->textures = ft_calloc(sizeof(t_textures), 1);
	main->game->textures->no = ft_strdup(parse->no);
	main->game->textures->so = ft_strdup(parse->so);
	main->game->textures->we = ft_strdup(parse->we);
	main->game->textures->ea = ft_strdup(parse->ea);
	main->game->textures->c = ft_pixel(parse->c[0], parse->c[1], \
		parse->c[2], 255);
	main->game->textures->f = ft_pixel(parse->f[0], parse->f[1], \
		parse->f[2], 255);
	ft_free_parse(parse, 0);
	ft_free_tab(tmp);
}
