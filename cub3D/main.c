/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:04:25 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/20 17:29:10 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cal_img(t_data *data)
{
	floor_ceiling_casting(data);
	wall_casting(data);
}

int	cub3d_loop(t_data *data)
{
	cal_img(data);
	draw(data);
	key_update(data);
	return (0);
}

int	finished(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_all(data);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error_exit(NULL, "arg_error\n");
	if (filecheck(&data, av))
	{
		ft_error("file_error!\n");
		return (1);
	}
	set_mlx(&data);
	load_tex(&data);
	mlx_loop_hook(data.mlx, &cub3d_loop, &data);
	mlx_hook(data.win, EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_hook(data.win, EVENT_KEY_RELEASE, 0, &reset_key, &data);
	mlx_hook(data.win, EVENT_KEY_EXIT, 0, &finished, &data);
	mlx_loop(data.mlx);
	return (0);
}
