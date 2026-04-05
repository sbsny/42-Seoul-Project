/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:47:28 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 01:48:57 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game_resources(t_game *map)
{
	free(map->map_data);
	if (map->mlx)
		free(map->mlx);
}

int	handle_close_window(t_game *map)
{
	mlx_destroy_window(map->mlx, map->win);
	free_game_resources(map);
	exit(EXIT_SUCCESS);
}
