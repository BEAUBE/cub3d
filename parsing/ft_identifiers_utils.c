/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:21:42 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/23 05:26:04 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_parse(t_parse *parse)
{
	int	i;

	i = 0;
	if (open(parse->no, F_OK, R_OK, X_OK) < 0
		|| open(parse->so, F_OK, R_OK, X_OK) < 0
		|| open(parse->we, F_OK, R_OK, X_OK) < 0
		|| open(parse->ea, F_OK, R_OK, X_OK) < 0)
	{
		ft_putstr_fd("Error\nOne texture doesn't exist\n", 2);
		ft_free_parse(parse, 2);
	}
	while (i != 3)
	{
		if ((parse->f[i] < 0 || parse->f[i] > 255)
			|| parse->c[i] < 0 || parse->c[i] > 255) 
		{
			ft_putstr_fd("Error\nColors must be between 0 and 255\n", 2);
			ft_free_parse(parse, 2);
		}
		i++;
	}
}

int	ft_all_identifiers(t_parse *parse)
{
	if (!parse->no || !parse->so || !parse->we || !parse->ea
		|| !parse->floor || !parse->ceiling)
		return (0);
	if (parse->no[ft_strlen(parse->no) - 1])
		parse->no[ft_strlen(parse->no) - 1] = 0;
	if (parse->so[ft_strlen(parse->so) - 1])
		parse->so[ft_strlen(parse->so) - 1] = 0;
	if (parse->we[ft_strlen(parse->we) - 1])
		parse->we[ft_strlen(parse->we) - 1] = 0;
	if (parse->ea[ft_strlen(parse->ea) - 1])
		parse->ea[ft_strlen(parse->ea) - 1] = 0;
	return (1);
}

int	ft_is_fill(t_parse *parse, char *s, char **id, char *line)
{
	if (s)
		ft_error_identifiers(parse, id, line);
	return (1);
}
