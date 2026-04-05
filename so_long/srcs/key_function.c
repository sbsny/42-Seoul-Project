/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:44:51 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 01:48:57 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	while (map->map_data[i] != 'P')
		i++;
	if (map->map_data[i - x] == 'E' && map->total_collectibles == map->collected_count)
	{
		map->is_game_over++;
		map->move_count++;
		ft_printf("Moves: %d\n", map->move_count);
	}
	if (map->map_data[i - x] != '1' && map->map_data[i - x] != 'E')
	{
		if (map->map_data[i - x] == 'C')
			map->collected_count++;
		map->map_data[i] = '0';
		map->map_data[i - x] = 'P';
		map->move_count++;
		ft_printf("Moves: %d\n", map->move_count);
	}
}

void	move_down(t_game *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	while (map->map_data[i] != 'P')
		i++;
	if (map->map_data[i + x] == 'E' && map->total_collectibles == map->collected_count)
	{
		map->is_game_over++;
		map->move_count++;
		ft_printf("Moves: %d\n", map->move_count);
	}
	if (map->map_data[i + x] != '1' && map->map_data[i + x] != 'E')
	{
		if (map->map_data[i + x] == 'C')
			map->collected_count++;
		map->map_data[i] = '0';
		map->map_data[i + x] = 'P';
		map->move_count++;
		ft_printf("Moves: %d\n", map->move_count);
	}
}

void	move_right(t_game *map)
{
	int	i;

	i = 0;
	while (map->map_data[i] != 'P')
		i++;
	if (map->map_data[i + 1] == 'E' && map->total_collectibles == map->collected_count)
	{
		map->is_game_over++;
		map->move_count++;
		ft_printf("Moves: %d\n", map->move_count);
	}
	if (map->map_data[i + 1] != '1' && map->map_data[i + 1] != 'E')
	{
		if (map->map_data[i + 1] == 'C')
			map->collected_count++;
		map->map_data[i] = '0';
		map->map_data[i + 1] = 'P';
		map->move_count++;
		ft_printf("Moves: %d\n", map->move_count);
	}
}

void	move_left(t_game *map)
{
	int	i;

	i = 0;
	while (map->map_data[i] != 'P')
		i++;
	if (map->map_data[i - 1] == 'E' && map->total_collectibles == map->collected_count)
	{
		map->is_game_over++;
		map->move_count++;
		ft_printf("Moves: %d\n", map->move_count);
	}
	if (map->map_data[i - 1] != '1' && map->map_data[i - 1] != 'E')
	{
		if (map->map_data[i - 1] == 'C')
			map->collected_count++;
		map->map_data[i] = '0';
		map->map_data[i - 1] = 'P';
		map->move_count++;
		ft_printf("Moves: %d\n", map->move_count);
	}
}

int	handle_key_input(int keycode, t_game *map)
{
	if (keycode == 53)
		map->is_game_over++;
	else if (keycode == 13)
		move_up(map);
	else if (keycode == 1)
		move_down(map);
	else if (keycode == 2)
		move_right(map);
	else if (keycode == 0)
		move_left(map);
	if (map->is_game_over > 0)
		handle_close_window(map);
	mlx_clear_window(map->mlx, map->win);
	render_map(map, 0);
	return (0);
}
