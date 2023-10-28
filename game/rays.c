/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:49:19 by ajoliet           #+#    #+#             */
/*   Updated: 2023/10/28 23:42:12 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_ray	*init_ray(t_main *main, int x, t_ray *ray)
{
	float	cam;

	cam = 2 * x / (float)W_SIZE_X - 1;
	ray->raydir_x = main->game->player.dirx + main->game->player.planex * cam;
	ray->raydir_y = main->game->player.diry + main->game->player.planey * cam;
	ray->posx = (int)main->game->player.posx;
	ray->posy = (int)main->game->player.posy;
	if (ray->raydir_x == 0)
		ray->delta_distx = 1e30;
	else
		ray->delta_distx = 1 / ray->raydir_x;
	if (ray->delta_distx < 0)
		ray->delta_distx *= -1.0;
	if (ray->raydir_y == 0)
		ray->delta_disty = 1e30;
	else
		ray->delta_disty = 1 / ray->raydir_y;
	if (ray->delta_disty < 0)
		ray->delta_disty *= -1.0;
	return (ray);
}

void	get_texture_posy(t_main *main, int x, int wall_size, int y)
{
	main->game->player.rays[x].texture_posy = ((float)y - (((float)W_SIZE_Y
					- (float)wall_size) / 2.0)) / (float)wall_size;
}
