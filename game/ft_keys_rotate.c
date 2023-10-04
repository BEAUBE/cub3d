/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:35:07 by slepetit          #+#    #+#             */
/*   Updated: 2023/10/04 04:44:13 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_rotate_left(t_player *player)
{
	float	oldirx;
	float	oldplanex;

	oldirx = player->dirx;
	player->dirx = player->dirx * cos(-0.04) - player->diry * sin(-0.04);
	player->diry = oldirx * sin(-0.04) + player->diry * cos(-0.04);
	oldplanex = player->planex;
	player->planex = player->planex * cos(-0.04) - player->planey * sin(-0.04);
	player->planey = oldplanex * sin(-0.04) + player->planey * cos(-0.04);
}

void	ft_rotate_right(t_player *player)
{
	float	oldirx;
	float	oldplanex;

	oldirx = player->dirx;
	player->dirx = player->dirx * cos(0.04) - player->diry * sin(0.04);
	player->diry = oldirx * sin(0.04) + player->diry * cos(0.04);
	oldplanex = player->planex;
	player->planex = player->planex * cos(0.04) - player->planey * sin(0.04);
	player->planey = oldplanex * sin(0.04) + player->planey * cos(0.04);
}
