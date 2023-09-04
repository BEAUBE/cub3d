/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:18:06 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/04 18:32:57 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_spawn_infos(t_main *main, char **map)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == 'N' || map[x][y] == 'W' || map[x][y] == 'S' || map[x][y] == 'E')
			{
				main->game->orientation = map[x][y];
				main->game->px = (float)x + 0.5;
				main->game->py = (float)y + 0.5;
				printf("%f, %f\n", main->game->px, main->game->py);
			}
			y++;
		}
	}
}

int	draw_f_c(t_main *main, int f[3], int c[3])
{
	int x;
	int y;
	int cc;
	int fc;

	(void)f;
	(void)c;
	cc = ft_pixel(250, 0, 250, 255);
	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 500)
		{
			mlx_put_pixel(main->game->img, x, y, cc);
			y++;
		}
		x++;
	}
	fc = ft_pixel(250, 250, 0, 255);
	x = 0;
	while (x < 1000)
	{
		y = 500;
		while (y >= 500 && y < 1000)
		{
			mlx_put_pixel(main->game->img, x, y, fc);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

void	ft_draw(void *param)
{
	t_main *main;

	main = param;
	draw_f_c(main, main->game->textures->f, main->game->textures->c);
}

int	ft_game(t_main *main)
{
	get_spawn_infos(main, main->parse->map);
	if (!(main->game->mlx = mlx_init(1000, 1000, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(main->game->img = mlx_new_image(main->game->mlx, 1000, 1000)))
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
	mlx_loop(main->game->mlx);
	mlx_terminate(main->game->mlx);
	return (EXIT_SUCCESS);
}
