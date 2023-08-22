/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:22:57 by ajoliet           #+#    #+#             */
/*   Updated: 2023/08/22 07:03:25 by slepetit         ###   ########.fr       */
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

typedef struct s_parse
{
	char	**map;
	int		lim;
	int		components;
	char	**identifiers;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
}	t_parse;

typedef struct s_textures
{
	int			fd_no;
	int			fd_we;
	int			fd_ea;
	int			fd_west;
	int			f[3];
	int			c[3];
}	t_textures;

typedef struct	s_game // si ca va pour Bob
{
	char		**map;
	int			pos[2];
	int			orientation;
	t_textures	*textures;
}	t_game;

typedef struct s_main
{
	mlx_t		*mlxptr;
	mlx_image_t	*mlximg;
	t_game		*game; // pas rempli encore
	t_parse		*parse;
}	t_main;

// INIT STRUCT
t_main	*ft_init_struct(t_main *main);

// FREE ERROR
void	ft_error_identifiers(t_parse *parse, char **id, char *line);
void	ft_error_map(t_main *main, int *pos);
void	ft_free_tab(char **tab);

// UTILS
int	ft_is_fill(t_parse *parse, char *s, char **id, char *line);
int		ft_all_identifiers(t_parse *parse);
void	skip_spaces(char *line, int *i);
int		ft_tablen(char **tab);

// IDENTIFIERS
int		check_nbr_element(char *line);
int		add_to_main(char *line);
void	ft_identifiers(t_parse *parse, char *file);

// MAP
void	ft_error_map(t_main *main, int *pos);
int		ft_components(char c, int *pos);
int		ft_map(t_main *main, char **s);

// PARSE
int		ft_get_lines(char *file);
t_parse	*ft_get_file(t_parse *parse, char *file);
void	ft_filename(char *file, int ac);
void	ft_parsing(t_main *main, char *file, int ac);

#endif
