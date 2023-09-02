/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:22:57 by ajoliet           #+#    #+#             */
/*   Updated: 2023/09/02 15:36:41 by ajoliet          ###   ########.fr       */
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
// peut etre des degres?

typedef struct s_parse
{
	char	**map;
	int		limit;
	int		compo;
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

typedef struct	s_game
{
	char		**map;
	float		px;
	float		py;
	char		orientation;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_textures	*textures;
}	t_game;

typedef struct s_main
{
	t_game		*game;
	t_parse		*parse;
}	t_main;

// PARSE
void	ft_file(char *file);
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
void	ft_map_limits(t_parse *parse, char *file);
t_parse	*ft_get_map(t_parse *parse, char *file);
int		ft_get_lines(char *file);
int		ft_longer_line(char **map);
void	ft_check_components(t_parse *parse, char c);
void	ft_map_components(t_parse *parse, char **map);
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
void	ft_error_newline(t_parse *parse, char *s1, char *s2);
void	ft_error_pos(t_parse *parse, t_game *game);
void	ft_error_identifiers(t_parse *parse, char **id, char *line);
void	ft_error_map(t_parse *parse, char **tmp);
void	ft_free_game(t_game *game);
void	ft_free_parse(t_parse *parse, int ex);
void	ft_free_tab(char **tab);

// GAME
int		ft_game(t_main *main);






#endif
