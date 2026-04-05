/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 06:00:29 by seonyun           #+#    #+#             */
/*   Updated: 2022/07/13 20:40:22 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (src[i] == '\0')
		return ((char *)dest);
	while (dest[i] && i < len)
	{
		j = 0;
		if (dest[i] == src[j])
		{
			while (src[j] && dest[i + j] == src[j] && (i + j) < len)
				j++;
			if (src[j] == '\0')
				return ((char *)dest + i);
		}
		i++;
	}
	return (NULL);
}
