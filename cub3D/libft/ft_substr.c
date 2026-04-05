/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunglee <sunglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:30:33 by sunglee           #+#    #+#             */
/*   Updated: 2023/02/06 13:30:34 by sunglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		*dest = 0;
		return (dest);
	}
	while (len > 0)
	{
		dest[i++] = s[start++];
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
