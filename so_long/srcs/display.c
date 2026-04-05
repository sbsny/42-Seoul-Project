/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:47:04 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 08:11:41 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_game *map)
{
	int	i;

	i = 100;
	map->wall = mlx_xpm_file_to_image(map->mlx, "imgs/wall.xpm", &i, &i);
	map->exit = mlx_xpm_file_to_image(map->mlx, "imgs/exit.xpm", &i, &i);
	map->item = mlx_xpm_file_to_image(map->mlx, "imgs/item.xpm", &i, &i);
	map->player = mlx_xpm_file_to_image(map->mlx, "imgs/player.xpm", &i, &i);
	map->space = mlx_xpm_file_to_image(map->mlx, "imgs/space.xpm", &i, &i);
	if (!map->wall || !map->exit || !map->item || !map->player || !map->space)
	{
		free(map->win);
		free(map->mlx);
		exit_with_error("Image file error\n", map);
	}
}

void	render_map(t_game *map, int i)
{
	int		x;
	int		y;
	char	*img;

	y = -1;
	while (y++ < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_data[i] == '1')
				img = map->wall;
			if (map->map_data[i] == '0')
				img = map->space;
			if (map->map_data[i] == 'C')
				img = map->item;
			if (map->map_data[i] == 'P')
				img = map->player;
			if (map->map_data[i] == 'E')
				img = map->exit;
			mlx_put_image_to_window(map->mlx, map->win, img, x * 100, y * 100);
			i++;
			x++;
		}
	}
}
