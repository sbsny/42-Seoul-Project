/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 07:49:33 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 08:35:51 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game_state(t_game *game)
{
	game->map_data = NULL;
	game->wall = NULL;
	game->exit = NULL;
	game->item = NULL;
	game->player = NULL;
	game->space = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->player_count = 0;
	game->is_game_over = 0;
	game->move_count = 0;
	game->collected_count = 0;
	game->total_collectibles = 0;
}

int	is_valid_map_format(char *map_name)
{
	int		i;
	char	*extension_name;

	extension_name = ".ber";
	i = 0;
	while (ft_strlen(map_name) != 4 && map_name)
		map_name++;
	if (!map_name || *map_name == '\0')
		return (0);
	while (map_name[i])
	{
		if (map_name[i] != extension_name[i])
			return (0);
		i++;
	}
	return (1);
}

void	start_window(t_game *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx,
			100 * map->width, 100 * map->height, "so_long subject");
	load_images(map);
	render_map(map, 0);
	mlx_hook(map->win, 17, 0, handle_close_window, map);
	mlx_key_hook(map->win, handle_key_input, map);
	mlx_loop(map->mlx);
}

void	run_game(char *map, t_game *game)
{
	int		fd;

	if (!is_valid_map_format(map))
		exit_with_error("Wrong map format\n", game);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_with_error("File does not exist\n", game);
	parse_map_file(fd, game);
	start_window(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game_state(&game);
	if (argc == 2)
	{
		run_game(argv[1], &game);
	}
	exit_with_error("Argument Number Error\n", &game);
	return (0);
}
