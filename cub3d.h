/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:22:57 by ajoliet           #+#    #+#             */
/*   Updated: 2023/08/09 14:53:36 by ajoliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "lib/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define S 4
# define F 5

typedef struct s_text_path
{
	char	*paths[4];
	int		*fds[4];
}	t_text_path;

typedef struct s_data
{
	t_text_path	text_path;
	char		**map;
	mlx_t		*mlxptr;
	mlx_image_t	*mlximg;
}	t_data;

void	ft_parsing(t_data *data, char *file, int ac);
void	ft_filename(char *file, int ac);
int		ft_strcmp(char *s1, char *s2);
t_data	*ft_gnl(t_data *data, char *file);
int		ft_gnl_lines(char *file);
void	skip_spaces(char *line, int *i);

#endif
