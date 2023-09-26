/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:18:06 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/26 18:21:51 by ajoliet          ###   ########.fr       */
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

void	draw_wall(t_main *main, int x, int wall_size)
{
	int i;
	int color;

	i = 0;
	if (main->game->player.rays[x].final_face == NO)
		color = ft_pixel(0, 0, 255, 255);
	else if (main->game->player.rays[x].final_face == SO)
		color = ft_pixel(0, 255, 255, 255);
	else if (main->game->player.rays[x].final_face == WE)
		color = ft_pixel(255, 255, 255, 255);
	else if (main->game->player.rays[x].final_face == EA)
		color = ft_pixel(255, 0, 255, 255);
	if (wall_size > 800)
		wall_size = 800;
	while ((wall_size / 2) > i)
	{
		mlx_put_pixel(main->game->img, x, 400 + i, color);
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
		draw_wall(main, i, main->game->player.rays[i].wall_size);
		i++;
	}
}

int	ft_game(t_main *main)
{
	main->game->player.posx = 2.5;
	main->game->player.posy = 2.5;
	main->game->player.dirx = -1.0;
	main->game->player.diry = 0;
	main->game->player.planex = 0;
	main->game->player.planey = 0.66;
	main->game->player.rays = malloc(sizeof(t_ray) * W_SIZE_X);
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
	mlx_loop_hook(main->game->mlx, ft_draw, main);
	mlx_loop_hook(main->game->mlx, ft_keys, main);
	mlx_loop(main->game->mlx);
	mlx_terminate(main->game->mlx);
	return (EXIT_SUCCESS);
}
