/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 05:22:40 by seonyun           #+#    #+#             */
/*   Updated: 2022/08/15 12:30:28 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str || !c)
		return (NULL);
	while (str[i] != (unsigned char)c && str[i])
		i++;
	if (str[i] == (unsigned char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	final = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final)
		return (NULL);
	while (s1[i])
		final[j++] = s1[i++];
	i = 0;
	while (s2[i])
		final[j++] = s2[i++];
	final[j] = '\0';
	free(s1);
	return (final);
}
