/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:03:22 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/26 18:21:40 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_wall_size(t_main *main, int x)
{
	t_ray	*ray;

	ray = &main->game->player.rays[x];
	init_ray(main, x, ray);
	get_collision(main, ray);
	get_dist(main, ray);
	ray->wall_size = (int)(W_SIZE_Y / ray->perpWallDist);
}

void	get_dist(t_main *main, t_ray *ray)
{
	(void)main;
	if (ray->side == 0)
		ray->perpWallDist = ray->sideDistx - ray->deltaDistx;
	else
		ray->perpWallDist = ray->sideDisty - ray->deltaDisty;
}

void	get_collision(t_main *main, t_ray *ray)
{
	ray->hit = 0;
	if (ray->raydir_x < 0)
	{
		ray->stepx = -1;
		ray->sideDistx = (main->game->player.posx - (float)ray->posx) * ray->deltaDistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sideDistx = ((float)ray->posx + 1.0 - main->game->player.posx) * ray->deltaDistx;
	}
	if (ray->raydir_y < 0)
	{
	  ray->stepy = -1;
	  ray->sideDisty = (main->game->player.posy - (float)ray->posy) * ray->deltaDisty;
	}
	else
	{
	  ray->stepy = 1;
	  ray->sideDisty = ((float)ray->posy + 1.0 - main->game->player.posy) * ray->deltaDisty;
	}
	while (!ray->hit)
	{
		if (ray->sideDistx < ray->sideDisty)
		{
			ray->sideDistx += ray->deltaDistx;
			ray->posx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sideDisty += ray->deltaDisty;
			ray->posy += ray->stepy;
			ray->side = 1;
		}
		if (main->game->map[ray->posy][ray->posx] && main->game->map[ray->posy][ray->posx] == '1')
		{
			ray->hit = 1;
			if (ray->side == 1 && ray->raydir_y > 0)
				ray->final_face = SO;
			else if (ray->side == 0 && ray->raydir_x > 0)
				ray->final_face = EA;
			else if (ray->side == 1)
				ray->final_face = NO;
			else
				ray->final_face = WE;
		}
	}
}

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
