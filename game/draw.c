/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:33:56 by ajoliet           #+#    #+#             */
/*   Updated: 2023/10/02 14:11:38 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor(t_main *main, int x, int end)
{
	int i;

	i = W_SIZE_Y - 1;
	while (i > end)
	{
		mlx_put_pixel(main->game->img, x, i, main->game->textures->f);
		i--;
	}
}

void	draw_ceiling(t_main *main, int x, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		mlx_put_pixel(main->game->img, x, i, main->game->textures->c);
		i++;
	}
}

void	get_texture_posy(t_main *main, int x, int wall_size, int y)
{	
	main->game->player.rays[x].texture_posy = ((float)y - (((float)W_SIZE_Y - (float)wall_size) / 2.0)) / (float)wall_size;
}

int	get_color(t_main *main, t_ray *ray)
{
	int x;
	int y;
	int color;
	mlx_image_t	*img;

	if (ray->final_face == NO)
		img = main->game->textures->t_no;
	else if (ray->final_face == SO)
		img = main->game->textures->t_so;
	else if (ray->final_face == WE)
		img = main->game->textures->t_we;
	else
		img = main->game->textures->t_ea;
	x = img->width * ray->texture_posx;
	y = img->height * ray->texture_posy;
	color = ft_pixel(img->pixels[(img->width * y + x) * 4], img->pixels[(img->width * y + x) * 4 + 1], img->pixels[(img->width * y + x) * 4 + 2], 255);
	return (color);
}

void	draw_wall(t_main *main, int x, int wall_size)
{
	int i;
	int color;

	i = 0;
	while ((wall_size / 2) > i && i < 400)
	{
		get_texture_posy(main, x, wall_size, 400 + i);
		color = get_color(main, &main->game->player.rays[x]);
		mlx_put_pixel(main->game->img, 999 - x, 400 + i, color);
		get_texture_posy(main, x, wall_size, 399 - i);
		color = get_color(main, &main->game->player.rays[x]);
		mlx_put_pixel(main->game->img, 999 - x, 399 - i, color);
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
