/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:18:02 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/16 21:12:54 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_close(t_data *data, char *str)
{
	int			i;
	int			len;
	static int	row = 0;

	i = 0;
	if (++row == 1)
		start_end_line(data, str);
	else if (row == data->map_h)
		start_end_line(data, str);
	while (str[i] == ' ')
		i++;
	len = ft_strlen(str);
	if (str[i] != '1' || str[len - 2] != '1')
	{
		ft_error_exit(data, "The map isn't closed.");
	}
}

void	start_end_line(t_data *data, char *str)
{
	size_t	i;

	i = 0;
	while (i < (ft_strlen(str) - 1))
	{
		if (str[i] != '1' && str[i] != ' ')
		{
			ft_error_exit(data, "The map isn't closed.\n");
		}
		i++;
	}
}

void	set_player(t_data *data, char **worldmap, int x, int y)
{
	if (worldmap[y][x + 1] == ' ' || worldmap[y][x - 1] == ' ')
		ft_error_exit(data, "The map isn't closed.");
	if (worldmap[y - 1][x] == ' ' || worldmap[y + 1][x] == ' ')
		ft_error_exit(data, "The map isn't closed.");
	data->view = data->worldmap[y][x];
	set_dir(data, worldmap[y][x]);
	worldmap[y][x] = '0';
	data->posx = (double)x + 0.5;
	data->posy = (double)y + 0.5;
}

void	check_map2(t_data *data, char **worldmap, int x, int y)
{
	if (worldmap[y][x] != '1' && worldmap[y][x] != 'N' && \
		worldmap[y][x] != 'E' && worldmap[y][x] != 'S' && \
		worldmap[y][x] != 'W' && worldmap[y][x] != '\n' && \
		worldmap[y][x] != ' ' && worldmap[y][x] != '0')
		ft_error_exit(data, "Wrong char in mapfile");
	if (worldmap[y][x] == '0')
	{
		if (worldmap[y][x + 1] == ' ' || worldmap[y][x - 1] == ' ')
			ft_error_exit(data, "The map isn't closed.");
		if (worldmap[y - 1][x] == ' ' || worldmap[y + 1][x] == ' ')
			ft_error_exit(data, "The map isn't closed.");
	}
}

void	check_map(t_data *data, char **worldmap)
{
	int	x;
	int	y;
	int	p_cnt;

	y = -1;
	p_cnt = 0;
	while (worldmap[++y])
	{
		x = -1;
		while (worldmap[y][++x])
		{
			check_map2(data, worldmap, x, y);
			if (worldmap[y][x] == 'N' || worldmap[y][x] == 'E' || \
				worldmap[y][x] == 'S' || worldmap[y][x] == 'W')
			{
				if (p_cnt == 1)
					ft_error_exit (data, "Too many player.");
				set_player(data, worldmap, x, y);
				p_cnt = 1;
			}
		}
	}
	if (p_cnt == 0)
		ft_error_exit(data, "Missing player.");
}
