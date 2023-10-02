/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:18:06 by ajoliet           #+#    #+#             */
/*   Updated: 2023/10/02 15:31:21 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_texture(t_main *main)
{
	mlx_texture_t	*tmp_txtr;

	tmp_txtr = mlx_load_png(main->game->textures->no);
	main->game->textures->t_no = mlx_texture_to_image(main->game->mlx, tmp_txtr);
	mlx_delete_texture(tmp_txtr);
	tmp_txtr = mlx_load_png(main->game->textures->so);
	main->game->textures->t_so = mlx_texture_to_image(main->game->mlx, tmp_txtr);
	mlx_delete_texture(tmp_txtr);
	tmp_txtr = mlx_load_png(main->game->textures->ea);
	main->game->textures->t_ea = mlx_texture_to_image(main->game->mlx, tmp_txtr);
	mlx_delete_texture(tmp_txtr);
	tmp_txtr = mlx_load_png(main->game->textures->we);
	main->game->textures->t_we = mlx_texture_to_image(main->game->mlx, tmp_txtr);
	mlx_delete_texture(tmp_txtr);
}

int	ft_game(t_main *main)
{
	/* west main->game->player.dirx = -1.0;
	main->game->player.diry = 0;
	main->game->player.planex = 0;
	main->game->player.planey = 0.66;*/
/* east	main->game->player.dirx = 1.0;
	main->game->player.diry = 0;
	main->game->player.planex = 0;
	main->game->player.planey = -0.66;*/
/* south	main->game->player.dirx = 0;
	main->game->player.diry = 1.0;
	main->game->player.planex = 0.66;
	main->game->player.planey = 0;*/
	main->game->player.dirx = 0;
	main->game->player.diry = -1.0;
	main->game->player.planex = -0.66;
	main->game->player.planey = 0;
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
	get_texture(main);
	mlx_loop_hook(main->game->mlx, ft_draw, main);
	mlx_loop_hook(main->game->mlx, ft_keys, main);
	mlx_loop(main->game->mlx);
	mlx_terminate(main->game->mlx);
	return (EXIT_SUCCESS);
}
