/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 05:32:32 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/23 06:05:14 by slepetit         ###   ########.fr       */
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

void    ft_find_pos(char **map, t_game *game)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
                || map[i][j] == 'W')
            {
				game->px = j;
				game->py = i;
				ft_orientation(game, map[i][j]);
            }
            j++;
        }
        i++;
    }
}

void    ft_fill_game(t_main *main, t_parse *parse)
{
    main->game = ft_calloc(sizeof(t_game), 1);
    main->game->textures = ft_calloc(sizeof(t_textures), 1);
    ft_find_pos(parse->map, main->game);
	ft_cpy_map(parse->map, main->game);
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