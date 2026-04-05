/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:52:05 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 08:34:13 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_game {
	char	*map_data;
	void	*wall;
	void	*exit;
	void	*item;
	void	*player;
	void	*space;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		player_count;
	int		is_game_over;
	int		move_count;
	int		collected_count;
	int		total_collectibles;
}				t_game;

void	free_game_resources(t_game *game);
int		handle_close_window(t_game *game);
void	load_images(t_game *game);
void	render_map(t_game *game, int tile_idx);
int		handle_key_input(int keycode, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	init_game_state(t_game *game);
int		is_valid_map_format(char *map_file);
void	start_window(t_game *game);
void	run_game(char *map_file, t_game *game);
char	*join_line_trim_newline(char *joined_map, char *line);
int		validate_line_border_and_chars(t_game *game, char **line, int idx);
int		parse_map_line(t_game *game, char **line, int fd);
void	validate_map_borders(t_game *game);
void	parse_map_file(int fd, t_game *game);
void	validate_map_counts(int exit_count, t_game *game);
void	exit_with_error(char *str, t_game *game);

#endif
