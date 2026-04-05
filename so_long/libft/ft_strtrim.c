/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 06:09:51 by seonyun           #+#    #+#             */
/*   Updated: 2022/07/12 18:46:49 by seonyun          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}		
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*arr;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (set_check(s1[i], set))
		i++;
	if (i == len)
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (set_check(s1[j], set))
		j--;
	arr = ft_substr(s1, i, j - i + 1);
	return (arr);
}
