/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:21:42 by slepetit          #+#    #+#             */
/*   Updated: 2023/10/04 04:48:12 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_spaces(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 32 && i != ft_strlen(line) - 1)
			return (0);
		i++;
	}
	return (1);
}

char	**ft_fill_rgb(t_parse *parse, char **id, char *line)
{
	char	**rgb;

	rgb = ft_split(id[1], ',');
	if (ft_tablen(rgb) != 3)
	{
		ft_free_tab(rgb);
		ft_error_identifiers(parse, id, line);
	}
	if (rgb[2][ft_strlen(rgb[2]) - 1] == '\n')
		rgb[2][ft_strlen(rgb[2]) - 1] = 0;
	return (rgb);
}

void	ft_check_identifiers(t_parse *parse)
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
