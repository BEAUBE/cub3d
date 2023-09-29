/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:03:20 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/29 20:11:39 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_main	main;

	ft_parsing(&main, av[1], ac);
	// ft_free_parse(main.parse, 0);
	ft_game(&main);
//	ft_free_game(main.game);
}
