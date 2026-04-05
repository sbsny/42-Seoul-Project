/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:29:06 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/20 17:28:43 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	tex_check(char *line)
{
	if (line[0] == 'N' && (line[1] == 'O' || line[1] == ' '))
		return (1);
	else if (line[0] == 'S' && (line[1] == 'O' || line[1] == ' '))
		return (2);
	else if (line[0] == 'W' && (line[1] == 'E' || line[1] == ' '))
		return (3);
	else if (line[0] == 'E' && (line[1] == 'A' || line[1] == ' '))
		return (4);
	else if (line[0] == 'F')
		return (5);
	else if (line[0] == 'C')
		return (6);
	else
		return (0);
}

void	tex_init2(t_data *data, char *line, int sw)
{
	if (sw == 4)
	{
		if (data->tex->ea != NULL)
			ft_error_exit(data, "Too many EA\n");
		data->tex->ea = save_arg(line);
	}
	else if (sw == 5)
	{
		if (data->tex->f != NULL)
			ft_error_exit(data, "Too many F\n");
		data->tex->f = save_arg(line);
	}
	else if (sw == 6)
	{
		if (data->tex->c != NULL)
			ft_error_exit(data, "Too many C\n");
		data->tex->c = save_arg(line);
	}
}

void	tex_init(t_data *data, char *line)
{
	int	sw;

	sw = tex_check(line);
	if (sw == 1)
	{
		if (data->tex->no != NULL)
			ft_error_exit(data, "Too many NO\n");
		data->tex->no = save_arg(line);
	}
	else if (sw == 2)
	{
		if (data->tex->so != NULL)
			ft_error_exit(data, "Too many SO\n");
		data->tex->so = save_arg(line);
	}
	else if (sw == 3)
	{
		if (data->tex->we != NULL)
			ft_error_exit(data, "Too many WE\n");
		data->tex->we = save_arg(line);
	}
	else
		tex_init2(data, line, sw);
}

void	load_img(t_data *data, int *tex, char *path, t_img *img)
{
	int	y;
	int	x;

	y = -1;
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_w, &img->img_h);
	if (!img->img)
		ft_error_exit(data, "path error\n");
	img->data = (int *)mlx_get_data_addr(img->img, \
	&img->bpp, &img->size_l, &img->endian);
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
		{
			tex[img->img_w * y + x] = img->data[img->img_w * y + x];
		}
	}
	mlx_destroy_image(data->mlx, img->img);
}

void	load_tex(t_data *data)
{
	t_img	img;

	load_img(data, data->texture[1], data->tex->ea, &img);
	load_img(data, data->texture[0], data->tex->we, &img);
	load_img(data, data->texture[2], data->tex->no, &img);
	load_img(data, data->texture[3], data->tex->so, &img);
}
