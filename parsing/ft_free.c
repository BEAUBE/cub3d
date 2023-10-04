/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:21:47 by slepetit          #+#    #+#             */
/*   Updated: 2023/10/04 03:27:23 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_game(t_game *game)
{
	if (game->textures->no)
		free(game->textures->no);
	if (game->textures->so)
		free(game->textures->so);
	if (game->textures->ea)
		free(game->textures->ea);
	if (game->textures->we)
		free(game->textures->we);
	if (game->textures)
		free(game->textures);
	if (game->map)
		ft_free_tab(game->map);
	free(game->player.rays);
	free(game);
}

void	ft_free_parse(t_parse *parse, int ex)
{
	if (parse->no)
		free(parse->no);
	if (parse->so)
		free(parse->so);
	if (parse->we)
		free(parse->we);
	if (parse->ea)
		free(parse->ea);
	if (parse->map)
		ft_free_tab(parse->map);
	free(parse);
	if (ex)
		exit(2);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
