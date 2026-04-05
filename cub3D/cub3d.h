/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:15:33 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/20 15:58:32 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define K_A 0
# define K_B 11
# define K_C 8
# define K_D 2
# define K_E 14
# define K_F 3
# define K_G 5
# define K_H 4
# define K_I 34
# define K_J 38
# define K_K 40
# define K_L 37
# define K_M 46
# define K_N 45
# define K_O 31
# define K_P 35
# define K_Q 12
# define K_R 15
# define K_S 1
# define K_T 17
# define K_U 32
# define K_V 9
# define K_W 13
# define K_X 7
# define K_Y 16
# define K_Z 6

# define K_RIGHT 123
# define K_LEFT 124

# define K_ESC 53

# define FPS 0.03
# define PI 3.1415926
# define R_ANG 1.57079632679

# define WIDTH 640
# define HEIGHT 480
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_KEY_EXIT 17

typedef struct s_ray
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	step;
	int		drawstart;
	int		drawend;
	int		lineheight;
	int		side;
	int		mapx;
	int		mapy;
}t_ray;

typedef struct s_oldmap
{
	char			*row;
	struct s_oldmap	*head;
	struct s_oldmap	*next;
}t_oldmap;

typedef struct s_error
{
	int	error;
}t_error;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
}	t_tex;

typedef struct s_data
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	char		view;
	char		**worldmap;
	int			map_h;
	int			map_w;
	void		*mlx;
	void		*win;
	int			**texture;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_w;
	int			key_r;
	int			key_l;
	double		buf[HEIGHT][WIDTH];
	t_oldmap	*oldmap;
	t_tex		*tex;
	t_img		img;
}	t_data;

void			ft_error(char *str);
void			free_list(t_data *old);
void			free_all(t_data *data);
void			ft_error_exit(t_data *data, char *str);
int				check_filename(char *s1, char *s2);
void			error_init(t_error *error);
int				tex_check(char *line);
char			*save_arg(char *line);
void			tex_init(t_data *data, char *line);
void			tex_init2(t_data *data, char *line, int sw);
void			check_error(t_data *data, int error);
void			start_end_line(t_data *data, char *str);
void			set_dir(t_data *data, char view);
void			tex_reset(t_tex *tex);
void			img_init(t_data *data);
void			data_init(t_data *data);
int				filecheck(t_data *data, char **av);
int				save_map(t_data *data, const char *filename);
void			printworldmap(t_data data);
void			set_mlx(t_data *data);
void			floor_ceiling_casting(t_data *data);
int				wall_texture_dir(t_data *data, t_ray *ray);
int				flashlight(int x, int y, int color);
int				choice_tex(t_data *data, t_ray *ray, int y, int x);
void			wall_line(t_data *data, t_ray *ray, double texx, int x);
void			wall_mapping(t_data *data, t_ray *ray, int x);
void			dda(t_data *data, t_ray *ray, int stepx, int stepy);
void			calculate_sidedist(t_data *data, t_ray *ray);
void			wall_casting(t_data *data);
void			cal_img(t_data *data);
void			draw(t_data *data);
int				cub3d_loop(t_data *data);
void			load_img(t_data *data, int *tex, char *path, t_img *img);
void			load_tex(t_data *data);
void			check_close(t_data *data, char *str);
void			checkfile(t_data *data, t_error *error);
void			add_map(t_data *data, char *str);
void			change_space(char **map);
void			set_map(t_data *data);
void			set_end(t_data *data, t_oldmap *tem, int i);
void			map_len(t_data *data, char *str);
void			parsing(t_data *data, int fd);
void			check_map(t_data *data, char **worldmap);
void			check_map2(t_data *data, char **worldmap, int x, int y);
void			set_player(t_data *data, char **worldmap, int x, int y);
void			key_option(int key);

int				key_press(int key, t_data *data);
int				key_update(t_data *data);
int				reset_key(int key, t_data *data);

unsigned int	tranc_color(char *str);

#endif
