/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:22:57 by ajoliet           #+#    #+#             */
/*   Updated: 2023/08/25 04:50:16 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "lib/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

# define NO 1
# define SO 2
# define EA 3
# define WE 4

typedef struct s_parse
{
	char	**map;
	int		lim;
	int		components;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		floor;
	int		c[3];
	int		ceiling;
}	t_parse;

typedef struct s_textures
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
}	t_textures;

typedef struct	s_game // si ca va pour Bob
{
	char		**map;
	int			px;
	int			py;
	int			orientation;
	mlx_t		*mlxptr;
	mlx_image_t	*mlximg;
	t_textures	*textures;
}	t_game;

typedef struct s_main
{
	t_game		*game; // pas rempli encore
	t_parse		*parse;
}	t_main;

// PARSE
int		ft_get_lines(char *file);
t_parse	*ft_get_file(t_parse *parse, char *file);
void	ft_filename(char *file, int ac);
t_main	*ft_parsing(t_main *main, char *file, int ac);

// IDENTIFIERS
int		ft_spaces(char *line);
char	**ft_fill_rgb(t_parse *parse, char **id, char *line);
void	ft_check_identifiers(t_parse *parse);
int		ft_is_fill(t_parse *parse, char *s, char **id, char *line);
int		ft_all_identifiers(t_parse *parse);
void	ft_rgb(t_parse *parse, char **id, char **rgb, char *line);
void	ft_info(t_parse *parse, char **id, char *line);
void	ft_id(t_parse *parse, char **id, char *line);
void	ft_check_line(t_parse *parse, char *line);
void	ft_identifiers(t_parse *parse, char *file);

// MAP
int		ft_longer_line(char **map);
char	**ft_fill_tmp(char **tmp, char **map);
char	**ft_set_tmp(int height, int width);
int		ft_map_close(char **tmp);
void	ft_map(t_parse *parse);

// FILL GAME
char	**ft_cpy_map(char **s, t_game *game);
void	ft_orientation(t_game *game, char c);
int		ft_find_pos(char **map, t_game *game);
void    ft_fill_game(t_main *main, t_parse *parse);

// UTILS
int		ft_tablen(char **tab);

// FREE ERROR
void	ft_error_newline(t_parse *parse, char **new);
void	ft_error_pos(t_parse *parse, t_game *game);
void	ft_error_identifiers(t_parse *parse, char **id, char *line);
void	ft_error_map(t_parse *parse, char **tmp);
void	ft_free_parse(t_parse *parse, int ex);
void	ft_free_tab(char **tab);






#endif
