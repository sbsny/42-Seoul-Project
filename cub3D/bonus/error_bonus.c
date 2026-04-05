/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:22:42 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/16 17:33:49 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	key_option(int key, t_data *data)
{
	if (key == K_E)
	{
		if (data->minimap_key == 1)
			data->minimap_key = 0;
		else
			data->minimap_key = 1;
	}
	if (key == K_ESC)
	{
		exit(0);
	}
}

void	ft_error(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
}

void	ft_error_exit(t_data *data, char *str)
{
	ft_error(str);
	free_all(data);
	exit(0);
}

void	error_init(t_error *error)
{
	error->error = 0;
}

void	check_error(t_data *data, int error)
{
	if (error == 1)
		ft_error_exit(data, "missing textures\n");
	else if (error == 2)
		ft_error_exit(data, "missing colors\n");
}
