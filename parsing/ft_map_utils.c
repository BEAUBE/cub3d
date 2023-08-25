/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:22:24 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/25 03:41:07 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_longer_line(char **map)
{
	size_t	i;
	size_t	longer;

	longer = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > longer)
			longer = ft_strlen(map[i]);
		i++;
	}
	return (longer);
}
