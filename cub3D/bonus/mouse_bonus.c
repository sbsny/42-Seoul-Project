/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:55:44 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/17 16:55:44 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mouse_ratate(t_data *data, double fps)
{
	double	m_fps;	
	double	old_dirx;
	double	old_planex;

	m_fps = fps * 2;
	old_dirx = data->dirx;
	data->dirx = data->dirx * cos(m_fps) - data->diry * sin(m_fps);
	data->diry = old_dirx * sin(m_fps) + data->diry * cos(m_fps);
	old_planex = data->planex;
	data->planex = data->planex * cos(m_fps) - data->planey * sin(m_fps);
	data->planey = old_planex * sin(m_fps) + data->planey * cos(m_fps);
}

int	mouse_move(int x, int y, t_data *data)
{
	static int	temx = 0;

	data->key_r = 0;
	data->key_l = 0;
	x = x * 5;
	if (temx)
	{
		if (x > 0 && x < WIDTH * 5 && y > 0 && y < HEIGHT && (temx - x) < 0)
		{
			mouse_ratate(data, FPS);
		}
		if (x > 0 && x < WIDTH * 5 && y > 0 && y < HEIGHT && (temx - x) > 0)
		{
			mouse_ratate(data, -FPS);
		}
	}
	temx = x;
	return (0);
}
