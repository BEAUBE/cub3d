/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:52:42 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/25 04:51:40 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_pos(t_parse *parse, t_game *game)
{
	ft_free_tab(game->map);
	free(game);
	ft_putstr_fd("Error\nWrong position", 2);
	ft_free_parse(parse, 2);
}

void	ft_error_identifiers(t_parse *parse, char **id, char *line)
{
	if (id)
		ft_free_tab(id);
	free(line);
	ft_putstr_fd("Error\nWrong identifiers\n", 2);
	ft_free_parse(parse, 2);
}

void	ft_error_map(t_parse *parse, char **tmp)
{
	ft_free_tab(tmp);
	ft_putstr_fd("Error\nMap is not closed", 2);
	ft_free_parse(parse, 2);
}

void	ft_error_newline(t_parse *parse, char **new)
{
	ft_free_tab(new);
	ft_putstr_fd("Error\nNewline in map", 2);
	ft_free_parse(parse, 2);
}
