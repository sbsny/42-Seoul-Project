/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:47:46 by seonyun           #+#    #+#             */
/*   Updated: 2022/07/13 17:45:14 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_arr(char **str, size_t	i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

static char	**split_strs(char const *s, char c, char **str, size_t num)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (i < num)
	{
		while (s[j] && s[j] == c)
			j++;
		len = 0;
		while (s[j + len] && s[j + len] != c)
			len++;
		str[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!str[i])
		{
			free_arr(str, i);
			return (NULL);
		}
		ft_strlcpy(str[i], &s[j], len + 1);
		j += len;
		i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	num;

	if (!s)
		return (NULL);
	num = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (num + 1));
	if (!str)
		return (NULL);
	str = split_strs(s, c, str, num);
	if (!str)
		return (NULL);
	str[num] = NULL;
	return (str);
}
