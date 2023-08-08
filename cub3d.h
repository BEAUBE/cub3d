/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:22:57 by ajoliet           #+#    #+#             */
/*   Updated: 2023/08/08 17:51:14 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	char		**map;
	mlx_t		*mlxptr;
	mlx_image_t	*mlximg;
}	t_data;

void	ft_parsing(t_data *data, char *file, int ac);
void	ft_filename(char *file, int ac);
int		ft_strcmp(char *s1, char *s2);
t_data	*ft_gnl(t_data *data, char *file);
int		ft_gnl_lines(char *file);

#endif
