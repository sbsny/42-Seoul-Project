/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:20:18 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/20 16:43:00 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_line(t_data *data, t_ray *ray, double texx, int x)
{
	int		y;
	int		texy;
	int		color;
	double	texpos;

	texpos = (ray->drawstart - HEIGHT / 2 + ray->lineheight / 2) * ray->step;
	y = ray->drawstart;
	while (y++ < ray->drawend)
	{
		texy = (int)texpos & (TEX_HEIGHT - 1);
		texpos += ray->step;
		color = choice_tex(data, ray, texy, texx);
		color = flashlight(x, y, color);
		data->buf[y][x] = color;
	}
}

void	wall_mapping(t_data *data, t_ray *ray, int x)
{
	int	texx;

	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
	ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT - 1;
	ray->step = 1.0 * TEX_HEIGHT / ray->lineheight;
	texx = wall_texture_dir(data, ray);
	wall_line(data, ray, texx, x);
}

void	dda(t_data *data, t_ray *ray, int stepx, int stepy)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += stepy;
			ray->side = 1;
		}
		if (data->worldmap[ray->mapy][ray->mapx] > '0')
			hit = 1;
	}
}
//#include <stdio.h>

void	calculate_sidedist(t_data *data, t_ray *ray)
{
	int	stepx;
	int	stepy;

	if (ray->raydirx < 0)
	{
		stepx = -1;
		ray->sidedistx = (data->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - data->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		stepy = -1;
		ray->sidedisty = (data->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - data->posy) * ray->deltadisty;
	}
	dda(data, ray, stepx, stepy);
}

void	wall_casting(t_data *data)
{
	int		x;
	t_ray	ray;

	x = -1;
	while (++x < WIDTH)
	{
		ray.camerax = (2 * x / (double)WIDTH) - 1;
		ray.raydirx = data->dirx + data->planex * ray.camerax;
		ray.raydiry = data->diry + data->planey * ray.camerax;
		ray.mapx = (int)data->posx;
		ray.mapy = (int)data->posy;
		ray.deltadistx = fabs(1 / ray.raydirx);
		ray.deltadisty = fabs(1 / ray.raydiry);
		calculate_sidedist(data, &ray);
		wall_mapping(data, &ray, x);
	}
}
