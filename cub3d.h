/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:22:57 by ajoliet           #+#    #+#             */
/*   Updated: 2023/11/08 21:07:18 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "lib/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

# define NO 1
# define SO 2
# define EA 3
# define WE 4

# define W_SIZE_X 1000
# define W_SIZE_Y 800

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
	mlx_image_t	*t_no;
	char		*so;
	mlx_image_t	*t_so;
	char		*we;
	mlx_image_t	*t_we;
	char		*ea;
	mlx_image_t	*t_ea;
	int			f;
	int			c;
}	t_textures;

typedef struct s_ray
{
	float	cam_var;
	float	raydir_x;
	float	raydir_y;
	float	side_distx;
	float	side_disty;
	float	delta_distx;
	float	delta_disty;
	float	perp_wall_dist;
	int		wall_size;
	int		posx;
	int		posy;
	int		stepx;
	int		stepy;
	int		side;
	int		final_face;
	int		final_dist;
	int		final_height;
	float	texture_posx;
	float	texture_posy;
	int		hit;
}	t_ray;

typedef struct s_player
{
	float	posx;
	float	posy;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
	t_ray	*rays;
}				t_player;

typedef struct s_game
{
	char		**map;
	int			max_x_map;
	int			max_y_map;
	t_player	player;
	int			orientation;
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
void	ft_fill_game(t_main *main, t_parse *parse);
char	**ft_set_walls(int height, int width);
char	**ft_fill_walls(char **tmp, char **map);

// UTILS
int		ft_comas(char *s);
int		ft_tablen(char **tab);
char	**ft_split_all(char **id);

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
t_ray	*init_ray(t_main *main, int x, t_ray *ray);
void	get_collision(t_main *main, t_ray *ray);
void	get_dist(t_main *main, t_ray *ray);
void	get_wall_size(t_main *main, int x);

//draw.c
void	ft_draw(void *param);
void	ft_keys(void *param);
void	ft_rotate_right(t_player *player);
void	ft_rotate_left(t_player *player);

//texture.c
void	get_texture_posy(t_main *main, int x, int wall_size, int y);
int		get_texture(t_main *main);

// MLX
int		ft_pixel(int r, int g, int b, int a);

#endif
