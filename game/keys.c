/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:47:24 by ajoliet           #+#    #+#             */
/*   Updated: 2023/10/04 03:27:48 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_keys(void *param)
{
	t_main *main;
	t_player	*player;
	float	oldirx;
	float	oldplanex;

	main = param;
	player = &main->game->player;
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_W))
    {
		if (player->posx + player->dirx * 0.08 < (float)main->game->max_x_map && player->posx + player->dirx * 0.08 > 1)
		player->posx += player->dirx * 0.03;
		if (player->posy + player->diry * 0.08 < (float)main->game->max_y_map && player->posy + player->diry * 0.08 > 1)
		player->posy += player->diry * 0.03;
    }
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_S))
    {
		if (player->posx - player->dirx * 0.08 < (float)main->game->max_x_map && player->posx - player->dirx * 0.08 > 1)
		player->posx -= player->dirx * 0.03;
		if (player->posy - player->diry * 0.08 < (float)main->game->max_y_map && player->posy - player->diry * 0.08 > 1)
		player->posy -= player->diry * 0.03;
    }
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_D))
    {
		if (player->posy + player->dirx * 0.08 < (float)main->game->max_y_map && player->posy + player->dirx * 0.08 > 1)
		player->posy += player->dirx * 0.03;
		if (player->posx - player->diry * 0.08 < (float)main->game->max_x_map && player->posx - player->diry * 0.08 > 1)
		player->posx -= player->diry * 0.03;
    }
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_A))
    {
		if (player->posy - player->dirx * 0.08 < (float)main->game->max_y_map && player->posy - player->dirx * 0.08 > 1)
		player->posy -= player->dirx * 0.03;
		if (player->posx + player->diry * 0.08 < (float)main->game->max_x_map && player->posx + player->diry * 0.08 > 1)
		player->posx += player->diry * 0.03;
    }
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_LEFT))
    {
		oldirx = player->dirx;
		player->dirx = player->dirx * cos(-0.04) - player->diry * sin(-0.04);
		player->diry = oldirx * sin(-0.04) + player->diry * cos(-0.04);
		oldplanex = player->planex;
		player->planex = player->planex * cos(-0.04) - player->planey * sin(-0.04);
		player->planey = oldplanex * sin(-0.04) + player->planey * cos(-0.04);
	}
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_RIGHT))
    {
		oldirx = player->dirx;
		player->dirx = player->dirx * cos(0.04) - player->diry * sin(0.04);
		player->diry = oldirx * sin(0.04) + player->diry * cos(0.04);
		oldplanex = player->planex;
		player->planex = player->planex * cos(0.04) - player->planey * sin(0.04);
		player->planey = oldplanex * sin(0.04) + player->planey * cos(0.04);
	}
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(main->game->mlx);
}
