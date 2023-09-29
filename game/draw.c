/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:33:56 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/29 20:01:53 by ajoliet          ###   ########.fr       */
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
/*
void	get_texture_pos(t_main *main, int x)
{
	
}
*/
void	draw_wall(t_main *main, int x, int wall_size)
{
	int i;
	int color;

	i = 0;
//	get_texture_pos(main, x);
	if (main->game->player.rays[x].final_face == NO)
		color = ft_pixel(0, 0, 255 * main->game->player.rays[x].texture_pos, 255);
	else if (main->game->player.rays[x].final_face == SO)
		color = ft_pixel(0, 255, 255 * main->game->player.rays[x].texture_pos, 255);
	else if (main->game->player.rays[x].final_face == WE)
		color = ft_pixel(255, 255 * main->game->player.rays[x].texture_pos, 255, 255);
	else if (main->game->player.rays[x].final_face == EA)
		color = ft_pixel(255, 0, 255, 255);
	if (wall_size > 800)
		wall_size = 800;
	while ((wall_size / 2) > i)
	{
		//color = get_texture_color(main, i, x, wall_size);
		mlx_put_pixel(main->game->img, x, 400 + i, color);
		//color = get_texture_color(main, i, x, wall_size);
		mlx_put_pixel(main->game->img, x, 400 - i, color);
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
		draw_ceiling(main, i, 400);
		draw_floor(main, i, 400);
		get_wall_size(main, i);
//		get_texture_pos(main, x);
		draw_wall(main, i, main->game->player.rays[i].wall_size);
		i++;
	}
}
