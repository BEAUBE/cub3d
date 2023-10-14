/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:03:22 by ajoliet           #+#    #+#             */
/*   Updated: 2023/10/14 23:36:05 by slepetit         ###   ########.fr       */
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
	ray->wall_size = (int)(W_SIZE_Y / ray->perp_wall_dist);
}

void	get_dist(t_main *main, t_ray *ray)
{
	int	tmp;

	if (ray->side == 0)
	{
		ray->perp_wall_dist = ray->side_distx - ray->delta_distx;
		ray->texture_posx = main->game->player.posy
			+ ray->perp_wall_dist * ray->raydir_y;
	}
	else
	{
		ray->perp_wall_dist = ray->side_disty - ray->delta_disty;
		ray->texture_posx = main->game->player.posx
			+ ray->perp_wall_dist * ray->raydir_x;
	}
	tmp = (int)ray->texture_posx;
	ray->texture_posx -= (float)tmp;
	if (ray->final_face == WE || ray->final_face == SO)
		ray->texture_posx = 1 - ray->texture_posx;
}

void	get_final_infos(t_main *main, t_ray *ray)
{
	ray->hit = 1;
	if (ray->side == 1 && ray->raydir_y > 0)
	{
		ray->final_face = SO;
		ray->texture_posx = (main->game->player.posx + ray->side_distx);
	}
	else if (ray->side == 0 && ray->raydir_x > 0)
	{
		ray->final_face = EA;
		ray->texture_posx = (main->game->player.posy + ray->side_disty);
	}
	else if (ray->side == 1)
	{
		ray->final_face = NO;
		ray->texture_posx = (main->game->player.posx + ray->side_distx);
	}
	else
	{
		ray->final_face = WE;
		ray->texture_posx = (main->game->player.posy + ray->side_disty);
	}
}

void	do_first_side(t_main *main, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->stepx = -1;
		ray->side_distx = (main->game->player.posx - (float)ray->posx)
			* ray->delta_distx;
	}
	else
	{
		ray->stepx = 1;
		ray->side_distx = ((float)ray->posx + 1.0 - main->game->player.posx)
			* ray->delta_distx;
	}
	if (ray->raydir_y < 0)
	{
		ray->stepy = -1;
		ray->side_disty = (main->game->player.posy - (float)ray->posy)
			* ray->delta_disty;
	}
	else
	{
		ray->stepy = 1;
		ray->side_disty = ((float)ray->posy + 1.0 - main->game->player.posy)
			* ray->delta_disty;
	}
}

void	get_collision(t_main *main, t_ray *ray)
{
	ray->hit = 0;
	do_first_side(main, ray);
	while (!ray->hit)
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_distx;
			ray->posx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->side_disty += ray->delta_disty;
			ray->posy += ray->stepy;
			ray->side = 1;
		}
		if (main->game->map[ray->posy][ray->posx]
				&& main->game->map[ray->posy][ray->posx] == '1')
			get_final_infos(main, ray);
	}
}
