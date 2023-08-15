/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:22:57 by ajoliet           #+#    #+#             */
/*   Updated: 2023/08/15 14:44:16 by ajoliet          ###   ########.fr       */
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

typedef struct s_graphics
{
	char	*path_north;
	char	*path_south;
	char	*path_east;
	char	*path_west;
	int		fd_north;
	int		fd_south;
	int		fd_east;
	int		fd_west;
}	t_graphics;

typedef struct s_data
{
	t_graphics	graphics;
	char		**map;
	mlx_t		*mlxptr;
	mlx_image_t	*mlximg;
}	t_data;

void	ft_parsing(t_data *data, char *file, int ac);
void	ft_filename(char *file, int ac);
void	ft_free_tab(char **tab);
int		ft_strcmp(char *s1, char *s2);
char	**ft_gnl(t_data *data, char *file);
int		ft_gnl_lines(char *file);
int		ft_map(t_data *data, char **s);
int		ft_components(char c, int *pos);
void	ft_error_map(t_data *data);
void	skip_spaces(char *line, int *i);

#endif
