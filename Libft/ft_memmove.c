/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 05:22:36 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/28 05:10:41 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dst;
	const unsigned char	*src1;

	if (dest == src || len == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	dst = (unsigned char *)dest;
	src1 = (const unsigned char *)src;
	if (dest < src)
		return (ft_memcpy(dest, src, len));
	while (len--)
		dst[len] = src1[len];
	return (dest);
}
