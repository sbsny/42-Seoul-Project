/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:30:29 by seonyun           #+#    #+#             */
/*   Updated: 2023/02/16 17:34:09 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_filename(char *s1, char *s2)
{
	char	*exec;

	exec = ft_strrchr(s1, '.');
	if (exec == NULL)
		return (1);
	if (ft_strncmp(exec, s2, ft_strlen(s2)))
		return (1);
	return (0);
}

int	filecheck(t_data *data, char **av)
{
	if (check_filename(av[1], ".cub"))
		return (1);
	save_map(data, av[1]);
	return (0);
}

int	save_map(t_data *data, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_error("open_error\n");
		exit(0);
	}
	data_init(data);
	parsing(data, fd);
	return (0);
}
