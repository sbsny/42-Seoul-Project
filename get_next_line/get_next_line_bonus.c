/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 07:35:26 by seonyun           #+#    #+#             */
/*   Updated: 2022/08/15 12:31:30 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*renew(char *str)
{
	int		i;
	int		j;
	char	*renewed;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	renewed = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!renewed)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		renewed[j++] = str[i++];
	renewed[j] = '\0';
	free(str);
	return (renewed);
}

char	*first_line(char *str)
{
	int		i;
	char	*first;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	first = (char *)malloc(sizeof(char) * (i + 2));
	if (!first)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		first[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		first[i] = str[i];
		i++;
	}
	first[i] = '\0';
	return (first);
}

char	*save_all(int fd, char *str)
{
	char	*buf;
	int		num;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	num = 1;
	while (!ft_strchr(str, '\n') && num)
	{
		num = read(fd, buf, BUFFER_SIZE);
		if (num == -1)
		{
			free(buf);
			return (NULL);
		}
		if (num == 0)
			break ;
		buf[num] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*first;
	static char	*str[10240];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	str[fd] = save_all(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	first = first_line(str[fd]);
	str[fd] = renew(str[fd]);
	return (first);
}
