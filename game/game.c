/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:18:06 by ajoliet           #+#    #+#             */
/*   Updated: 2023/10/06 06:07:44 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_max_map(t_main *main)
{
	int	i;

	i = 0;
	while (main->game->map[i])
			i++;
	main->game->max_y_map = i - 1;
	i = 0;
	while (main->game->map[1][i])
			i++;
	main->game->max_x_map = i - 1;
}

void	set_orientation(t_main *main)
{
	main->game->player.dirx = 0;
	main->game->player.diry = 0;
	main->game->player.planex = 0;
	main->game->player.planey = 0;
	if (main->game->orientation == NO)
	{
		main->game->player.diry = -1.0;
		main->game->player.planex = -0.66;
	}
	else if (main->game->orientation == SO)
	{
		main->game->player.diry = 1.0;
		main->game->player.planex = 0.66;
	}
	else if (main->game->orientation == EA)
	{
		main->game->player.dirx = -1.0;
		main->game->player.planey = 0.66;
	}
	else if (main->game->orientation == WE)
	{
		main->game->player.dirx = 1.0;
		main->game->player.planey = -0.66;
	}
}

void	ft_play(t_main *main)
{
	set_orientation(main);
	get_texture(main);
	get_max_map(main);
	mlx_loop_hook(main->game->mlx, ft_draw, main);
	mlx_loop_hook(main->game->mlx, ft_keys, main);
	mlx_loop(main->game->mlx);
	// mlx_delete_image(main->game->mlx, main->game->img);
	mlx_terminate(main->game->mlx);
}

int	ft_game(t_main *main)
{
	main->game->player.rays = malloc(sizeof(t_ray) * W_SIZE_X);
	main->game->mlx = mlx_init(W_SIZE_X, W_SIZE_Y, "MLX42", true);
	if (!main->game->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	main->game->img = mlx_new_image(main->game->mlx, W_SIZE_X, W_SIZE_Y);
	if (!main->game->img)
	{
		mlx_close_window(main->game->mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(main->game->mlx, main->game->img, 0, 0) == -1)
	{
		mlx_close_window(main->game->mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	ft_play(main);
	ft_free_game(main->game);
	return (EXIT_SUCCESS);
}
