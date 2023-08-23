/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:54:08 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/23 05:15:48 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_main    *ft_init_struct(t_main *main)
{
    main->parse = ft_calloc(sizeof(t_parse), 1);
    if (!main->parse)
        return (NULL);
    return (main);
}