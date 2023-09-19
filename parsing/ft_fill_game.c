/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 05:32:32 by slepetit          #+#    #+#             */
/*   Updated: 2023/09/14 17:54:25 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	un strdup de la map
*/

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
		ft_printf("%s\n", game->map[i]);
		i++;
	}
	return (game->map);
}

/*
	Rempli l'orientation, tu peux changer en degres
*/

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

/*
	Trouve la position du joueur
*/

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

/*
	Rempli les infos de la strut parse dans la struct game
*/

void	ft_fill_game(t_main *main, t_parse *parse)
{
	main->game = ft_calloc(sizeof(t_game), 1);
	if (!ft_find_pos(parse->map, main->game))
		ft_error_pos(parse, main->game);
	ft_cpy_map(parse->map, main->game);
	main->game->textures = ft_calloc(sizeof(t_textures), 1);
	main->game->textures->no = ft_strdup(parse->no);
	main->game->textures->so = ft_strdup(parse->so);
	main->game->textures->we = ft_strdup(parse->we);
	main->game->textures->ea = ft_strdup(parse->ea);
	main->game->textures->f[0] = parse->f[0];
	main->game->textures->f[1] = parse->f[1];
	main->game->textures->f[2] = parse->f[2];
	main->game->textures->c[0] = parse->c[0];
	main->game->textures->c[1] = parse->c[1];
	main->game->textures->c[2] = parse->c[2];
	ft_free_parse(parse, 0);
}
