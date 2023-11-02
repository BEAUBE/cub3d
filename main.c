/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:03:20 by ajoliet           #+#    #+#             */
/*   Updated: 2023/11/02 23:18:16 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_main	main;

	if (ac > 2)
	{
		ft_printf("Only one argumemnt for this program\n");
		exit(2);
	}
	ft_parsing(&main, av[1], ac);
	ft_game(&main);
	return (0);
}
