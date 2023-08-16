/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:17:43 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/16 02:21:29 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_nbr_element(char *line)
{
	char **tab;
	static int	nbr_infos;

	tab = ft_split(line, ' ');
	if (tab[0][0] == '\n')
	{
		ft_free_tab(tab);
		return (1);
	}
	if (ft_tablen(tab) != 3)
	{
		ft_free_tab(tab);
		return (0);
	}
	else
		nbr_infos += 1;
	if (nbr_infos == 7)
	{
		ft_free_tab(tab);
		return (0);
	}
	if (nbr_infos < 7 && ft_isdigit(tab[0][0]))
	{
		ft_free_tab(tab);
		return (0);
	}
	return (1);
}

int	add_to_main(t_main *main, char *line)
{
	(void)main;
	check_nbr_element(line);
	return (0);
}

void	ft_collect_infos(char *file, t_main *main)
{
	char *line;
	int fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		add_to_main(main, line);
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_printf("%s", line);
	}
	free(line);
	close(fd);
}