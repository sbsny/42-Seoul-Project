/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:49 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/20 16:06:34 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_end(t_data *data, t_oldmap *tem, int i)
{
	int	len;

	len = ft_strlen(tem->row);
	ft_strlcpy(data->worldmap[i], tem->row, len + 1);
	if (i == data->map_h - 1)
	{
		if (data->worldmap[i][len - 1] != '\n')
			len++;
	}
	if (len < data->map_w + 1)
	{
		ft_memset((void *)&data->worldmap[i][len - 1], ' ', \
					data->map_w - len);
		data->worldmap[i][data->map_w - 1] = '\n';
		data->worldmap[i][data->map_w] = '\0';
	}
}

void	set_map(t_data *data)
{
	int			i;
	t_oldmap	*tem;

	i = -1;
	tem = data->oldmap;
	data->worldmap = malloc(sizeof(char *) * data->map_h + 1);
	data->worldmap[data->map_h] = NULL;
	while (tem != NULL)
	{
		check_close(data, tem->row);
		data->worldmap[++i] = malloc(sizeof(char) * (data->map_w + 2));
		set_end(data, tem, i);
		tem = tem->next;
	}
	check_map(data, data->worldmap);
	change_space(data->worldmap);
	data->map_w -= 1;
}

void	map_len(t_data *data, char *str)
{
	int			i;
	static int	max_len = 0;

	i = 0;
	i = ft_strlen(str);
	if (i > max_len)
		max_len = i;
	data->map_h++;
	data->map_w = max_len;
	add_map(data, str);
}

void	parsing(t_data *data, int fd)
{
	char	*line;
	t_error	error;

	error_init(&error);
	line = get_next_line(fd);
	while (line)
	{
		checkfile(data, &error);
		tex_init(data, line);
		if (error.error == 0 && (ft_strchr(line, '1') || ft_strchr(line, '0')))
			map_len(data, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_error(data, error.error);
	set_map(data);
}
