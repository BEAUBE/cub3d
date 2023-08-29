/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:52:42 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/29 06:11:05 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_pos(t_parse *parse, t_game *game)
{
	free(game);
	ft_putstr_fd("Error\nNeed a position (N,S,W,E)\n", 2);
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
	ft_putstr_fd("Error\nMap is not closed\n", 2);
	ft_free_parse(parse, 2);
}

void	ft_error_newline(t_parse *parse, char *s1, char *s2)
{
	free(s1);
	free(s2);
	ft_putstr_fd("Error\nNewline in map\n", 2);
	ft_free_parse(parse, 2);
}
