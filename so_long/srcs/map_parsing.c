/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:46:36 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 09:25:16 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*join_line_trim_newline(char *s1, char *s2)
{
	char	*new;
	char	*tmp;

	if (!s1)
		return (ft_strtrim(s2, "\n"));
	tmp = ft_strjoin(s1, s2);
	new = ft_strtrim(tmp, "\n");
	free(tmp);
	return (new);
}

void	validate_map_borders(t_game *map)
{
	int	i;
	int	j;

	i = map->width;
	while (i > -1)
	{
		if (map->map_data[i] != '1')
			exit_with_error("Not surrounded by correct size of the wall\n", map);
		i--;
	}
	i = map->width;
	j = ft_strlen(map->map_data);
	while (i > -1)
	{
		if (map->map_data[j - 1] != '1')
			exit_with_error("Not surrounded by correct size of the wall\n", map);
		j--;
		i--;
	}
}

int	validate_line_border_and_chars(t_game *map, char **line, int i)
{
	if ((*line)[i] != '1')
	{
		if ((*line)[i] != '1' && (*line)[i] != '0' && (*line)[i] != 'C'
			&& (*line)[i] != 'E' && (*line)[i] != 'P' && (*line)[i] != '\0'
			&& (*line)[i] != '\n')
		{
			free(*line);
			exit_with_error("Wrong Character Type\n", map);
		}
		free(*line);
		exit_with_error("Not surrounded by correct size of the wall\n", map);
	}
	return (1);
}

int	parse_map_line(t_game *map, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = validate_line_border_and_chars(map, line, 0);
	while ((*line)[i + 1] != '\n' && (*line)[i + 1])
	{
		if ((*line)[i] != '1' && (*line)[i] != '0' && (*line)[i] != 'C'
			&& (*line)[i] != 'E' && (*line)[i] != 'P')
		{
			free(*line);
			exit_with_error("Wrong Character Type\n", map);
		}
		i++;
	}
	i = i + validate_line_border_and_chars(map, line, i);
	tmp = map->map_data;
	map->map_data = join_line_trim_newline(tmp, *line);
	free(tmp);
	free(*line);
	if (i != map->width && map->width != 0)
		exit_with_error("Not surrounded by correct size of the wall\n", map);
	*line = get_next_line(fd);
	map->height++;
	return (i);
}

void	parse_map_file(int fd, t_game *game)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit_with_error("Nothing in files\n", game);
	while (line)
		game->width = parse_map_line(game, &line, fd);
	close(fd);
	validate_map_borders(game);
	i = 0;
	fd = 0;
	while (game->map_data[fd])
	{
		if (game->map_data[fd] == 'C')
			game->total_collectibles++;
		if (game->map_data[fd] == 'P')
			game->player_count++;
		if (game->map_data[fd] == 'E')
			i++;
		fd++;
	}
	validate_map_counts(i, game);
}
