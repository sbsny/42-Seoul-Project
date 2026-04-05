/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:17:27 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/20 17:33:43 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_dir2(t_data *data, char view)
{
	if (view == 'W')
	{
		data->dirx = -1.0;
		data->diry = 0.0;
		data->planex = 0.0;
		data->planey = -0.66;
	}
	else
	{
		data->dirx = 0.0;
		data->diry = 1.0;
		data->planex = 0.66;
		data->planey = 0.0;
	}
}

void	set_dir(t_data *data, char view)
{
	if (view == 'N')
	{
		data->dirx = 0.0;
		data->diry = -1.0;
		data->planex = -0.66;
		data->planey = 0.0;
	}
	else if (view == 'E')
	{
		data->dirx = 1.0;
		data->diry = 0.0;
		data->planex = 0.0;
		data->planey = 0.66;
	}
	else
		set_dir2(data, view);
}

void	img_init(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->texture = (int **)malloc(sizeof(int *) * 5);
	if (!data->texture)
		ft_error_exit(data, "malloc error!\n");
	while (++i < 4)
	{
		data->texture[i] = (int *)malloc(sizeof(int) \
						* (TEX_WIDTH * TEX_HEIGHT));
		if (!data->texture[i])
			ft_error_exit(data, "malloc error!\n");
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < TEX_WIDTH * TEX_HEIGHT)
		{
			data->texture[i][j] = '0';
		}
		data->texture[i][j] = '\0';
	}
	data->texture[i] = 0;
}

void	data_init(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	data->map_h = 0;
	data->map_w = 0;
	data->key_s = 0;
	data->key_a = 0;
	data->key_d = 0;
	data->key_r = 0;
	data->key_l = 0;
	data->minimap_key = 0;
	data->map_h = 0;
	data->map_w = 0;
	data->oldmap = NULL;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			data->buf[y][x] = 0;
	}
	data->tex = (t_tex *)malloc(sizeof(t_tex));
	tex_reset(data->tex);
	img_init(data);
}

void	tex_reset(t_tex *tex)
{
	tex->no = NULL;
	tex->so = NULL;
	tex->ea = NULL;
	tex->we = NULL;
	tex->c = NULL;
	tex->f = NULL;
}
