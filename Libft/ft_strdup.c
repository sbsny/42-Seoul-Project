/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:18:34 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/29 03:32:51 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s) + 1;
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	dest = ft_memcpy(dest, s, len);
	return (dest);
}
