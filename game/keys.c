/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 01:47:00 by y ajoliet         #+#    #+#             */
/*   Updated: 2023/10/19 20:17:55 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_key_a(t_main *main, t_player *player)
{
	if (player->posy - player->dirx * 0.1 < (float)main->game->max_y_map - 0.2
		&& player->posy - player->dirx * 0.1 > 1.2)
		player->posy -= player->dirx * 0.03;
	if (player->posx + player->diry * 0.1 < (float)main->game->max_x_map - 0.2
		&& player->posx + player->diry * 0.1 > 1.2)
		player->posx += player->diry * 0.03;
}

void	ft_key_d(t_main *main, t_player *player)
{
	if (player->posy + player->dirx * 0.1 < (float)main->game->max_y_map - 0.2
		&& player->posy + player->dirx * 0.1 > 1.2)
		player->posy += player->dirx * 0.03;
	if (player->posx - player->diry * 0.1 < (float)main->game->max_x_map - 0.2
		&& player->posx - player->diry * 0.1 > 1.2)
		player->posx -= player->diry * 0.03;
}

void	ft_key_s(t_main *main, t_player *player)
{
	if (player->posx - player->dirx * 0.1 < (float)main->game->max_x_map - 0.2
		&& player->posx - player->dirx * 0.1 > 1.2)
		player->posx -= player->dirx * 0.03;
	if (player->posy - player->diry * 0.1 < (float)main->game->max_y_map - 0.2
		&& player->posy - player->diry * 0.1 > 1.2)
		player->posy -= player->diry * 0.03;
}

void	ft_key_w(t_main *main, t_player *player)
{
	if (player->posx + player->dirx * 0.1 < (float)main->game->max_x_map - 0.2
		&& player->posx + player->dirx * 0.1 > 1.2)
		player->posx += player->dirx * 0.03;
	if (player->posy + player->diry * 0.1 < (float)main->game->max_y_map - 0.2
		&& player->posy + player->diry * 0.1 > 1.2)
		player->posy += player->diry * 0.03;
}

void	ft_keys(void *param)
{
	t_main		*main;
	t_player	*player;

	main = param;
	player = &main->game->player;
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_W))
		ft_key_w(main, player);
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_S))
		ft_key_s(main, player);
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_D))
		ft_key_d(main, player);
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_A))
		ft_key_a(main, player);
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_LEFT))
		ft_rotate_left(player);
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_RIGHT))
		ft_rotate_right(player);
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(main->game->mlx);
}
