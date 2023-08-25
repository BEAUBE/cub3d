/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:21:47 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/25 04:44:02 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_parse(t_parse *parse, int ex)
{
	free(parse->no);
	free(parse->so);
	free(parse->we);
	free(parse->ea);
	ft_free_tab(parse->map);
	free(parse);
	if (ex)
		exit(2);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
