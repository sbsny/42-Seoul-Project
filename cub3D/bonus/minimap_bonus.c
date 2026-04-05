/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:17:30 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/16 17:33:29 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	minimap_wall(t_data *data, t_minimap *mini, int x, int y)
{
	if ((x - mini->st) % (mini->bl_size + 1))
	{
		if ((y - mini->h_st) % (mini->bl_size + 1) && mini->mapy < data->map_h)
		{
			if (data->minimap_ch && data->worldmap[mini->mapy][mini->mapx] \
				> '0')
				data->buf[y][x] = 0x00CCFFCC;
		}
	}
	else
	{
		mini->mapx++;
		if (mini->mapx >= data->map_w)
		{
			mini->mapx = 0;
			data->minimap_ch = 0;
		}
	}
}

void	set_minimap(t_minimap *mini)
{
	mini->mapx = 0;
	mini->mapy = 0;
	mini->bl_size = 1;
}

void	max_bl_size(t_data *data, t_minimap *mini)
{
	int	min_dist;
	int	max_cnt;
	int	i;

	i = 10;
	if (data->map_h < data->map_w)
		max_cnt = data->map_w;
	else
		max_cnt = data->map_h;
	min_dist = HEIGHT - 80;
	while ((i * max_cnt) < min_dist)
	{
		if (mini->bl_size < i)
			mini->bl_size = i;
		i++;
	}
	mini->wid = (mini->bl_size + 1) * data->map_w + 2;
	mini->hei = (mini->bl_size + 1) * data->map_h + 2;
}

void	minimap_player(t_data *data, t_minimap *mini, int x, int y)
{
	double	x_dist;
	double	y_dist;

	x_dist = (data->posx * (mini->bl_size + 1)) - x + (mini->st);
	y_dist = (data->posy * (mini->bl_size + 1)) - y + (mini->h_st);
	if (data->minimap_ch && (x_dist * x_dist) + (y_dist * y_dist) < \
		((mini->bl_size / 4) * (mini->bl_size / 4)))
	{
		data->buf[y][x] = 0x00FF0000;
	}
}

void	minimap_init(t_data *data, t_ray *ray)
{
	int			x;
	int			y;
	t_minimap	mini;

	(void)ray;
	set_minimap(&mini);
	max_bl_size(data, &mini);
	y = (HEIGHT - mini.hei) / 2;
	mini.h_st = y;
	while (++y < (HEIGHT - ((HEIGHT - mini.hei) / 2)))
	{
		x = (WIDTH - mini.wid) / 2;
		mini.st = x;
		data->minimap_ch = 1;
		if ((y - mini.h_st) % (mini.bl_size + 1) == 0)
			mini.mapy++;
		while (++x < (WIDTH - (WIDTH - mini.wid) / 2))
		{
			if (x % 3 && y % 3)
				data->buf[y][x] = 0xCCFFFFFF;
			minimap_wall(data, &mini, x, y);
			minimap_player(data, &mini, x, y);
		}
	}
}
