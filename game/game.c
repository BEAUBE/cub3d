/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:18:06 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/29 20:25:07 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
/*
void	get_texture(t_main *main, char *path)
{
	mlx_texture_t	*mlx_texture_tmp;
	mlx_image_t		*mlx_image_tmp;

	mlx_texture_tmp = mlx_load_png(path);
	mlx_image_tmp = mlx_texture_to_image(main->game->mlx, mlx_texture_tmp);
	texture = get_texture_from_mlx(mlx_image_tmp);
	lx_delete_texture(mlx_texture_tmp);
	mlx_delete_image(main->game->mlx, mlx_image_tmp);
}
*/
int	ft_game(t_main *main)
{
	main->game->player.dirx = -1.0;
	main->game->player.diry = 0;
	main->game->player.planex = 0;
	main->game->player.planey = 0.66;
	main->game->player.rays = malloc(sizeof(t_ray) * W_SIZE_X);
	main->game->textures->t_no = mlx_load_png(main->game->textures->no);
	main->game->textures->t_so = mlx_load_png(main->game->textures->so);
	main->game->textures->t_ea = mlx_load_png(main->game->textures->ea);
	main->game->textures->t_we = mlx_load_png(main->game->textures->we);
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
