/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:03:20 by ajoliet           #+#    #+#             */
/*   Updated: 2023/10/01 14:40:52 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_main	main;

	ft_parsing(&main, av[1], ac);
//	ft_free_parse(main.parse, 0);
	ft_game(&main);
//	ft_free_game(main.game);
}
