/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:08:51 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/15 15:06:41 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_map(t_data *data)
{
	ft_free_tab(data->map);
//	free(data);
	exit(2);
}

int	ft_components(char c, int *pos)
{
	if (c != '1' && c != '0' && c!= 'N' && c != 'S' && c != 'E' && c != 'W')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		*pos += 1;
	if (*pos > 1)
		return (1);
	return (0);
}

int	ft_map(t_data *data, char **s)
{
	int	x;
	int	y;
	int	pos;

	x = 0;
	y = 0;
	pos = 0;
	while(s[x])
	{
		y = 0;
		while(s[x][y])
		{
			if (ft_components(s[x][y], &pos))
				ft_error_map(data);
			y++;
		}
		x++;
	}
	return (0);
}
