/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 05:05:44 by slepetit          #+#    #+#             */
/*   Updated: 2023/10/06 06:10:35 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_delete_textures(t_main *main)
{
	if (main->game->textures->t_no)
		mlx_delete_image(main->game->mlx, main->game->textures->t_no);
	if (main->game->textures->t_so)
		mlx_delete_image(main->game->mlx, main->game->textures->t_so);
	if (main->game->textures->t_ea)
		mlx_delete_image(main->game->mlx, main->game->textures->t_ea);
	if (main->game->textures->t_we)
		mlx_delete_image(main->game->mlx, main->game->textures->t_we);
}

void	check_texture(t_main *main, mlx_texture_t *tmp_txtr)
{
	if (!tmp_txtr)
	{
		ft_delete_textures(main);
		ft_free_game(main->game);
		mlx_delete_image(main->game->mlx, main->game->img);
		exit(2);
	}
}

int	get_texture(t_main *main)
{
	mlx_texture_t	*tmp_txtr;

	tmp_txtr = mlx_load_png(main->game->textures->no);
	check_texture(main, tmp_txtr);
	main->game->textures->t_no = mlx_texture_to_image(main->game->mlx,
			tmp_txtr);
	mlx_delete_texture(tmp_txtr);
	tmp_txtr = mlx_load_png(main->game->textures->so);
	check_texture(main, tmp_txtr);
	main->game->textures->t_so = mlx_texture_to_image(main->game->mlx,
			tmp_txtr);
	mlx_delete_texture(tmp_txtr);
	tmp_txtr = mlx_load_png(main->game->textures->ea);
	check_texture(main, tmp_txtr);
	main->game->textures->t_ea = mlx_texture_to_image(main->game->mlx,
			tmp_txtr);
	mlx_delete_texture(tmp_txtr);
	tmp_txtr = mlx_load_png(main->game->textures->we);
	check_texture(main, tmp_txtr);
	main->game->textures->t_we = mlx_texture_to_image(main->game->mlx,
			tmp_txtr);
	mlx_delete_texture(tmp_txtr);
	return (0);
}
