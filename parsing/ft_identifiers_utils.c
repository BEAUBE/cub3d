/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:21:42 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/22 06:55:29 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_all_identifiers(t_parse *parse)
{
	if (!parse->no || !parse->so || !parse->we || !parse->ea)
		return (0);
	return (1);
}

int	ft_is_fill(t_parse *parse, char *s, char **id, char *line)
{
	if (s)
		ft_error_identifiers(parse, id, line);
	return (1);
}
