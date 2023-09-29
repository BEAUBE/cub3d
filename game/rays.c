/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:49:19 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/28 15:29:57 by ajoliet          ###   ########.fr       */
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
		ray->deltaDistx = 1e30;
	else
		ray->deltaDistx = 1 / ray->raydir_x;
	if (ray->deltaDistx < 0)
		ray->deltaDistx *= -1.0;
	if (ray->raydir_y == 0)
		ray->deltaDisty = 1e30;
	else
		ray->deltaDisty = 1 / ray->raydir_y;
	if (ray->deltaDisty < 0)
		ray->deltaDisty *= -1.0;
	return (ray);
}

void	get_rays(t_main *main)
{
	(void)main;
	t_ray	*rays;

	rays = malloc(sizeof(t_ray) * W_SIZE_X);
}
