/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:22:24 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/28 18:17:03 by slepetit         ###   ########.fr       */
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

void	ft_check_components(t_parse *parse, char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W' && c != 32)
	{
		ft_putstr_fd("Error\nWrong components (0,1,N,S,E,W and space)", 2);
		ft_free_parse(parse, 2);
	}
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && parse->compo == 1)
	{
		ft_putstr_fd("Error\nOnly on player on the map", 2);
		ft_free_parse(parse, 2);
	}
	else if ((c == 'N' || c == 'S' || c == 'E' || c == 'W')
		&& parse->compo == 0)
		parse->compo = 1;
}
