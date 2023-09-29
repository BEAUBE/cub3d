/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:03:22 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/29 21:18:14 by ajoliet          ###   ########.fr       */
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
	int tmp;
	if (ray->side == 0)
	{
		ray->perpWallDist = ray->sideDistx - ray->deltaDistx;
		ray->texture_posx = main->game->player.posy + ray->perpWallDist * ray->raydir_y;
	}
	else
	{
		ray->perpWallDist = ray->sideDisty - ray->deltaDisty;
		ray->texture_posx = main->game->player.posx + ray->perpWallDist * ray->raydir_x;
	}
	tmp = (int)ray->texture_posx;
	ray->texture_posx -= (float)tmp;
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
			{
				ray->final_face = SO;
				ray->texture_posx = (main->game->player.posx + ray->sideDistx);
			}
			else if (ray->side == 0 && ray->raydir_x > 0)
			{
				ray->final_face = EA;
				ray->texture_posx = (main->game->player.posy + ray->sideDisty);
			}
			else if (ray->side == 1)
			{
				ray->final_face = NO;
				ray->texture_posx = (main->game->player.posx + ray->sideDistx);
			}
			else
			{
				ray->final_face = WE;
				ray->texture_posx = (main->game->player.posy + ray->sideDisty);
			}
		}
	}
}
