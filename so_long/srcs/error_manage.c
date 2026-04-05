/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:50:31 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 06:37:42 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_map_counts(int i, t_game *game)
{
	if (game->width == game->height)
		exit_with_error("Not rectangular\n", game);
	else if (game->player_count != 1)
		exit_with_error("Must be one player or contain at least one E or C\n", game);
	else if (i == 0)
		exit_with_error("Must be at least one exit or collectible\n", game);
	else if (game->total_collectibles == 0)
		exit_with_error("Must be at least one collectible\n", game);
}

void	exit_with_error(char *str, t_game *game)
{
	if (game->map_data)
		free(game->map_data);
	write(1, "Error\n", 6);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}
