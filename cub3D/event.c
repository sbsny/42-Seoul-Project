/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:17:53 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/20 17:37:44 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_view(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	if (data->key_l == 1)
	{
		old_dirx = data->dirx;
		data->dirx = data->dirx * cos(FPS) - data->diry * sin(FPS);
		data->diry = old_dirx * sin(FPS) + data->diry * cos(FPS);
		old_planex = data->planex;
		data->planex = data->planex * cos(FPS) - data->planey * sin(FPS);
		data->planey = old_planex * sin(FPS) + data->planey * cos(FPS);
	}
	if (data->key_r == 1)
	{
		old_dirx = data->dirx;
		data->dirx = data->dirx * cos(-FPS) - data->diry * sin(-FPS);
		data->diry = old_dirx * sin(-FPS) + data->diry * cos(-FPS);
		old_planex = data->planex;
		data->planex = data->planex * cos(-FPS) - data->planey * sin(-FPS);
		data->planey = old_planex * sin(-FPS) + data->planey * cos(-FPS);
	}
}

void	key_move(t_data *data)
{
	double	right_x;
	double	right_y;

	if (data->key_a == 1)
	{
		right_x = data->dirx * cos(-R_ANG) - data->diry * sin(-R_ANG);
		right_y = data->dirx * sin(R_ANG) + data->diry * cos(R_ANG);
		if (data->worldmap[(int)(data->posy - right_y * (FPS + 0.1))] \
		[(int)data->posx] == '0')
			data->posy -= right_y * FPS;
		if (data->worldmap[(int)data->posy] \
		[(int)(data->posx + right_x * (FPS + 0.1))] == '0')
			data->posx += right_x * FPS;
	}
	if (data->key_d == 1)
	{
		right_x = data->dirx * cos(R_ANG) - data->diry * sin(R_ANG);
		right_y = data->dirx * sin(-R_ANG) + data->diry * cos(-R_ANG);
		if (data->worldmap[(int)(data->posy - right_y * (FPS + 0.1))] \
		[(int)data->posx] == '0')
			data->posy -= right_y * FPS;
		if (data->worldmap[(int)data->posy] \
		[(int)(data->posx + right_x * (FPS + 0.1))] == '0')
			data->posx += right_x * FPS;
	}
}

int	key_press(int key, t_data *data)
{
	if (key == K_W)
		data->key_w = 1;
	else if (key == K_S)
		data->key_s = 1;
	else if (key == K_A)
		data->key_a = 1;
	else if (key == K_D)
		data->key_d = 1;
	else if (key == K_RIGHT)
		data->key_r = 1;
	else if (key == K_LEFT)
		data->key_l = 1;
	key_option(key);
	return (0);
}

int	reset_key(int key, t_data *data)
{
	if (key == K_W)
		data->key_w = 0;
	else if (key == K_S)
		data->key_s = 0;
	else if (key == K_A)
		data->key_a = 0;
	else if (key == K_D)
		data->key_d = 0;
	else if (key == K_RIGHT)
		data->key_r = 0;
	else if (key == K_LEFT)
		data->key_l = 0;
	key_option(key);
	return (0);
}

int	key_update(t_data *data)
{
	if (data->key_w == 1)
	{
		if (data->worldmap[(int)(data->posy + data->diry * (FPS + 0.1))] \
						[(int)data->posx] == '0')
			data->posy += data->diry * FPS;
		if (data->worldmap[(int)data->posy] \
						[(int)(data->posx + data->dirx * (FPS + 0.1))] == '0')
			data->posx += data->dirx * FPS;
	}
	if (data->key_s == 1)
	{
		if (data->worldmap[(int)(data->posy - data->diry * (FPS + 0.1))] \
							[(int)data->posx] == '0')
			data->posy -= data->diry * FPS;
		if (data->worldmap[(int)data->posy] \
						[(int)(data->posx - data->dirx * (FPS + 0.1))] == '0')
			data->posx -= data->dirx * FPS;
	}
	key_move(data);
	key_view(data);
	return (0);
}
