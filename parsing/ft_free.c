/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:21:47 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/28 20:15:42 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_game(t_game *game)
{
	free(game->textures->no);
	free(game->textures->so);
	free(game->textures->ea);
	free(game->textures->we);
	free(game->textures);
	ft_free_tab(game->map);
	free(game);
}

void	ft_free_parse(t_parse *parse, int ex)
{
	free(parse->no);
	free(parse->so);
	free(parse->we);
	free(parse->ea);
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
