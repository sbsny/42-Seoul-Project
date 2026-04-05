/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunglee <sunglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:27:45 by sunglee           #+#    #+#             */
/*   Updated: 2023/02/06 13:27:47 by sunglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (dest < s)
		ft_memcpy(dest, src, len);
	else
	{
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(s + len);
	}
	return (dest);
}
