/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:33:56 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/29 23:37:21 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor(t_main *main, int x, int end)
{
	int i;
	int	fc;

	i = W_SIZE_Y - 1;
	fc = ft_pixel(250, 0, 250, 255);
	while (i > end)
	{
		mlx_put_pixel(main->game->img, x, i, fc);
		i--;
	}
}

void	draw_ceiling(t_main *main, int x, int end)
{
	int i;
	int	cc;

	i = 0;
	cc = ft_pixel(250, 250, 0, 255);
	while (i < end)
	{
		mlx_put_pixel(main->game->img, x, i, cc);
		i++;
	}
}

void	get_texture_posy(t_main *main, int x, int wall_size, int y)
{	
	main->game->player.rays[x].texture_posy = ((float)y - (((float)W_SIZE_Y - (float)wall_size) / 2.0)) / (float)wall_size;
}

void	draw_wall(t_main *main, int x, int wall_size)
{
	int i;
	int color;

	i = 0;
	if (main->game->player.rays[x].final_face == NO)
		color = ft_pixel(0, 255 * main->game->player.rays[x].texture_posy, 255 * main->game->player.rays[x].texture_posx, 255);
	else if (main->game->player.rays[x].final_face == SO)
		color = ft_pixel(0, 255 * main->game->player.rays[x].texture_posy, 255 * main->game->player.rays[x].texture_posx, 255);
	else if (main->game->player.rays[x].final_face == WE)
		color = ft_pixel(0, 255 * main->game->player.rays[x].texture_posy, 255 * main->game->player.rays[x].texture_posx, 255);
	else if (main->game->player.rays[x].final_face == EA)
		color = ft_pixel(0, 255 * main->game->player.rays[x].texture_posy, 255 * main->game->player.rays[x].texture_posx, 255);
	while ((wall_size / 2) > i && i < 400)
	{
		get_texture_posy(main, x, wall_size, 400 + i);
//		mlx_put_pixel(main->game->img, 999 - x, 400 + i, color);
		mlx_put_pixel(main->game->img, 999 - x, 400 + i, ft_pixel(0, 255 * main->game->player.rays[x].texture_posy, 255 * main->game->player.rays[x].texture_posx, 255));
		get_texture_posy(main, x, wall_size, 399 - i);
//		mlx_put_pixel(main->game->img, 999 - x, 399 - i, color);
		mlx_put_pixel(main->game->img, 999 - x, 399 - i, ft_pixel(0, 255 * main->game->player.rays[x].texture_posy, 255 * main->game->player.rays[x].texture_posx, 255));
		i++;
	}
}

void	ft_draw(void *param)
{
	t_main *main;
	int i;

	i = 0;
	main = param;
	while (i < W_SIZE_X)
	{
		draw_ceiling(main, 999 - i, 400);
		draw_floor(main, 999 - i, 400);
		get_wall_size(main, i);
		draw_wall(main, i, main->game->player.rays[i].wall_size);
		i++;
	}
}
