/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:18:06 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/02 15:38:11 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_pixel(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

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
			}
			y++;
		}
	}
}

void	draw_f_c(t_main *main, int f[3], int c[3])
{
	int x;
	int y;
	int cc;
	int fc;

	cc = ft_pixel(c[0], c[1], c[2], 0);
	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 500)
		{
			mlx_put_pixel(main->game->img, 0, 0, cc);
			y++;
		}
		x++;
	}
	fc = ft_pixel(f[0], f[1], f[2], 0);
	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y > 500 && y < 1000)
		{
			mlx_put_pixel(main->game->img, 0, 0, fc);
			y++;
		}
		x++;
	}
}

void	ft_draw(void *param)
{
	t_main *main;

	main = param;
	draw_f_c(main, main->game->textures->f, main->game->textures->c);
	get_spawn_infos(main, main->game->map);
}

int	ft_game(t_main *main)
{
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
	mlx_loop_hook(main->game->mlx, ft_draw, main);
	if (mlx_image_to_window(main->game->mlx, main->game->img, 0, 0) == -1)
	{
		mlx_close_window(main->game->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
