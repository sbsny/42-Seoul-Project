/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:27:48 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/16 15:59:12 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	tranc_color(char *str)
{
	unsigned int	rgb[3];
	int				i;
	int				j;
	char			**sp;

	i = 0;
	sp = ft_split(str, ',');
	while (sp[i] && i < 3)
	{
		j = -1;
		rgb[i] = 0;
		while (sp[i][++j])
		{
			while (ft_isdigit((int)sp[i][j]))
			{
				rgb[i] = (rgb[i] * 10) + (sp[i][j] - '0');
				j++;
			}
		}
		i++;
	}
	return (((0 & 0xFF) << 24) + ((rgb[0] & 0xFF) << 16) + \
			((rgb[1] & 0xFF) << 8) + (rgb[2] & 0xFF));
}

int	wall_texture_dir(t_data *data, t_ray *ray)
{
	double	wallx;
	int		texx;

	if (ray->side == 0)
		wallx = data->posy + ray->perpwalldist * ray->raydiry;
	else
		wallx = data->posx + ray->perpwalldist * ray->raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * TEX_WIDTH);
	if ((ray->side == 0 && ray->raydirx < 0) || \
		(ray->side == 1 && ray->raydiry > 0))
		texx = TEX_WIDTH - texx - 1;
	return (texx);
}

int	flashlight(int x, int y, int color)
{
	double	distx;
	double	disty;

	distx = x - WIDTH / 2;
	disty = y - HEIGHT / 2;
	if ((distx * distx + disty * disty) < 40000)
		return (color);
	else
		return ((color >> 1) & 8355711);
}

int	choice_tex(t_data *data, t_ray *ray, int y, int x)
{
	int	ret;

	if (ray->side == 0 && ray->raydirx > 0)
		ret = data->texture[1][TEX_HEIGHT * y + x];
	else if (ray->side == 0 && ray->raydirx <= 0)
		ret = data->texture[0][TEX_HEIGHT * y + x];
	else if (ray->side == 1 && ray->raydiry > 0)
		ret = data->texture[3][TEX_HEIGHT * y + x];
	else
		ret = data->texture[2][TEX_HEIGHT * y + x];
	return (ret);
}
