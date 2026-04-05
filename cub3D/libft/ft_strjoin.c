/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunglee <sunglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:29:23 by sunglee           #+#    #+#             */
/*   Updated: 2023/02/06 13:29:24 by sunglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		p;
	char	*dest;

	i = 0;
	p = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
		dest[p++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		dest[p++] = s2[i++];
	dest[p] = '\0';
	return (dest);
}
