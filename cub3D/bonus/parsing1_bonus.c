/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:18:06 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/16 17:33:17 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*save_arg(char *line)
{
	int		i;
	int		st;
	int		len;
	char	*tem;

	i = 2;
	len = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	st = i;
	while (line[i] != '\n')
	{
		len++;
		i++;
	}
	tem = ft_substr(line, st, len);
	return (tem);
}

void	checkfile(t_data *data, t_error *error)
{
	if (!data->tex->no || !data->tex->we || !data->tex->ea || !data->tex->so)
		error->error = 1;
	else if (!data->tex->c || !data->tex->f)
		error->error = 2;
	else
		error->error = 0;
}

void	add_map(t_data *data, char *str)
{
	t_oldmap	*tem;

	tem = malloc(sizeof(t_oldmap));
	tem->row = ft_strdup(str);
	tem->next = NULL;
	if (data->oldmap == NULL)
	{
		tem->head = tem;
		data->oldmap = tem;
	}
	else
	{
		while (data->oldmap->next)
			data->oldmap = data->oldmap->next;
		tem->head = data->oldmap->head;
		data->oldmap->next = tem;
	}
	data->oldmap = tem->head;
}

void	change_space(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == ' ')
				map[y][x] = '1';
		}
	}
}
