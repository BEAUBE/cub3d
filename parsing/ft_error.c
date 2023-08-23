/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:52:42 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/23 05:26:22 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_identifiers(t_parse *parse, char **id, char *line)
{
	ft_free_tab(id);
	free(line);
	ft_putstr_fd("Error\nWrong identifiers\n", 2);
	ft_free_parse(parse, 2);
}

void	ft_error_map(t_main *main, int *pos)
{
	if (*pos == 0)
		ft_putstr_fd("Error\nMap must be composed with 0,1,N,S,E,W\n", 2);
	else if (*pos > 1)
		ft_putstr_fd("Error\nMap must be composed with only one player \
			position\n", 2);
	ft_free_tab(main->parse->map);
	ft_free_parse(main->parse, 2);
}