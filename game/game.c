/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:18:06 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/25 19:53:46 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_f_c(t_main *main)
{
	int x;
	int y;
	int cc;
	int fc;

	x = 0;
	cc = ft_pixel(250, 0, 250, 255);
	while (x < W_SIZE_X)
	{
		y = 0;
		while (y < (W_SIZE_Y / 2))
		{
			mlx_put_pixel(main->game->img, x, y, cc);
			y++;
		}
		x++;
	}
	fc = ft_pixel(250, 250, 0, 255);
	x = 0;
	while (x < W_SIZE_X)
	{
		y = 500;
		while (y >= (W_SIZE_Y / 2) && y < W_SIZE_Y)
		{
			mlx_put_pixel(main->game->img, x, y, fc);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

void	draw_floor(t_main *main, int x, int end)
{
	int i;
	int	fc;

	i = W_SIZE_Y - 1;
	fc = ft_pixel(250, 0, 250, 255);
	while (i > end)
	{
		mlx_put_pixel(main->game->img, x, i, fc);
		i--;
	}
}

void	draw_ceiling(t_main *main, int x, int end)
{
	int i;
	int	cc;

	i = 0;
	cc = ft_pixel(250, 250, 0, 255);
	while (i < end)
	{
		mlx_put_pixel(main->game->img, x, i, cc);
		i++;
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

void	get_collision(t_main *main, t_ray *ray)
{
	ray->hit = 0;
	//printf("%i, %f, %f\n", x, ray->raydir_x, ray->raydir_y);
	if (ray->raydir_x < 0)
	{
		ray->stepx = -1;
		ray->sideDistx = (main->game->player.posx - ray->posx) * ray->deltaDistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sideDistx = (ray->posx + 1.0 - main->game->player.posx) * ray->deltaDistx;
	}
	if (ray->raydir_y < 0)
	{
	  ray->stepy = -1;
	  ray->sideDisty = (main->game->player.posy - ray->posy) * ray->deltaDisty;
	}
	else
	{
	  ray->stepy = 1;
	  ray->sideDisty = (ray->posy + 1.0 - ray->posy) * ray->deltaDisty;
	}
	//printf("%f : x = %f, y = %f\n", ray->cam_var, ray->raydir_x, ray->raydir_y);
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
			ray->hit = 1;
	}
}

void	get_dist(t_main *main, t_ray *ray)
{
	(void)main;
	if (ray->side == 0)
		ray->perpWallDist = ray->sideDistx - ray->deltaDistx;
	else
		ray->perpWallDist = ray->sideDisty - ray->deltaDisty;
}

void	get_wall_dist(t_main *main, t_ray *ray)
{
	get_collision(main, ray);
	get_dist(main, ray);
}

void	get_wall_size(t_main *main, int x)
{
	t_ray	*ray;

	ray = &main->game->player.rays[x];
	init_ray(main, x, ray);
	get_wall_dist(main, ray);
	ray->wall_size = (int)(W_SIZE_Y / ray->perpWallDist);
	//printf("%f\n", ray->perpWallDist);
}

void	draw_wall(t_main *main, int x, int wall_size)
{
	int i;

	i = 0;
	if (wall_size > 800)
		wall_size = 800;
	while ((wall_size / 2) > i)
	{
		mlx_put_pixel(main->game->img, x, 400 + i, ft_pixel(0, 250, 0, 255));
		mlx_put_pixel(main->game->img, x, 400 - i, ft_pixel(0, 250, 0, 255));
		i++;
	}
}

void	ft_draw(void *param)
{
	t_main *main;
	int i;

	i = 0;
	main = param;
	while (i < W_SIZE_X)
	{
		draw_ceiling(main, i, 400);
		draw_floor(main, i, 400);
		get_wall_size(main, i);
		draw_wall(main, i, main->game->player.rays[i].wall_size);
		i++;
	}
	//printf("%f, %f\n", main->game->player.dirx, main->game->player.diry);
}

void	ft_keys(void *param)
{
	t_main *main;
	t_player	*player;
	float	oldirx;
	float	oldplanex;

	main = param;
	player = &main->game->player;
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_W))
    {
		player->posx += player->dirx * 0.01;
		player->posy += player->diry * 0.01;
    }
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_S))
    {
		player->posx -= player->dirx * 0.01;
		player->posy -= player->diry * 0.01;
    }
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_A))
    {
		player->posy += player->dirx * 0.01;
		player->posx += player->diry * 0.01;
    }
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_D))
    {
		player->posy -= player->dirx * 0.01;
		player->posx -= player->diry * 0.01;
    }
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_E))
    {
		oldirx = player->dirx;
		player->dirx = player->dirx * cos(-0.04) - player->diry * sin(-0.04);
		player->diry = oldirx * sin(-0.04) + player->diry * cos(-0.04);
		oldplanex = player->planex;
		player->planex = player->planex * cos(-0.04) - player->planey * sin(-0.04);
		player->planey = oldplanex * sin(-0.04) + player->planey * cos(-0.04);
	}
	if (mlx_is_key_down(main->game->mlx, MLX_KEY_Q))
    {
		oldirx = player->dirx;
		player->dirx = player->dirx * cos(0.04) - player->diry * sin(0.04);
		player->diry = oldirx * sin(0.04) + player->diry * cos(0.04);
		oldplanex = player->planex;
		player->planex = player->planex * cos(0.04) - player->planey * sin(0.04);
		player->planey = oldplanex * sin(0.04) + player->planey * cos(0.04);
	}
}

int	ft_game(t_main *main)
{
	main->game->player.posx = 2.5;
	main->game->player.posy = 2.5;
	main->game->player.dirx = -1.0;
	main->game->player.diry = 0;
	main->game->player.planex = 0;
	main->game->player.planey = 0.66;
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
	mlx_loop_hook(main->game->mlx, ft_draw, main);
	mlx_loop_hook(main->game->mlx, ft_keys, main);
	mlx_loop(main->game->mlx);
	mlx_terminate(main->game->mlx);
	return (EXIT_SUCCESS);
}
