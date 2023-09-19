/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:18:06 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/19 18:24:41 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_f_c(t_main *main)
{
	int x;
	int y;
	int cc;
	int fc;

	x = 0;
	cc = ft_pixel(250, 0, 250, 255);
	while (x < W_SIZE_X)
	{
		y = 0;
		while (y < (W_SIZE_Y / 2))
		{
			mlx_put_pixel(main->game->img, x, y, cc);
			y++;
		}
		x++;
	}
	fc = ft_pixel(250, 250, 0, 255);
	x = 0;
	while (x < W_SIZE_X)
	{
		y = 500;
		while (y >= (W_SIZE_Y / 2) && y < W_SIZE_Y)
		{
			mlx_put_pixel(main->game->img, x, y, fc);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

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

t_ray	*init_ray(t_main *main, int x, t_ray *ray)
{
	float	cam;

	cam = 2 * x / (float)W_SIZE_X - 1;
	ray->raydir_x = main->game->player.dirx + cam;
	ray->raydir_y = main->game->player.diry + cam;
	ray->posx = main->game->player.posx;
	ray->posy = main->game->player.posy;
	if (ray->raydir_x == 0)
		ray->deltaDistx = 1e20;
	else
		ray->deltaDistx = 1 / ray->raydir_x;
	if (ray->deltaDistx < 0)
		ray->deltaDistx *= -1;
	if (ray->raydir_y == 0)
		ray->deltaDisty = 1e20;
	else
		ray->deltaDisty = 1 / ray->raydir_y;
	if (ray->deltaDisty < 0)
		ray->deltaDisty *= -1;
	return (ray);
}

void	get_wall_size(t_main *main, int x)
{
	t_ray	*ray;

	ray = &main->game->player.rays[x];
	init_ray(main, x, ray);
//	get_wall_dist(main, x, ray);
}

void	ft_draw(void *param)
{
	t_main *main;
	int i;

	i = 0;
	main = param;
	while (i < W_SIZE_X)
	{
		get_wall_size(main, i);
		draw_ceiling(main, i, 300);
		draw_floor(main, i, 700);
		i++;
	}
}

int	ft_game(t_main *main)
{
	if (!(main->game->mlx = mlx_init(W_SIZE_X, W_SIZE_Y, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(main->game->img = mlx_new_image(main->game->mlx, W_SIZE_X, W_SIZE_Y)))
	{
		mlx_close_window(main->game->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(main->game->mlx, main->game->img, 0, 0) == -1)
	{
		mlx_close_window(main->game->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	main->game->player.posx = 26.5;
	main->game->player.posy = 11.5;
	main->game->player.dirx = 0.0;
	main->game->player.diry = -1.0;
	main->game->player.rays = malloc(sizeof(t_ray) * W_SIZE_X);
	mlx_loop_hook(main->game->mlx, ft_draw, main);
	mlx_loop(main->game->mlx);
	mlx_terminate(main->game->mlx);
	return (EXIT_SUCCESS);
}
