/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:17:45 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/16 15:31:36 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_ceiling_casting(t_data *data)
{
	int				y;
	int				x;
	unsigned long	f_col;
	unsigned long	c_col;

	y = HEIGHT / 2;
	f_col = tranc_color(data->tex->f);
	c_col = tranc_color(data->tex->c);
	while (y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			data->buf[y][x] = f_col;
			data->buf[HEIGHT - y][x] = c_col;
		}
		y++;
	}
}

void	draw(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			data->img.data[y * WIDTH + x] = data->buf[y][x];
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
