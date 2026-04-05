/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:00:24 by seonyun           #+#    #+#             */
/*   Updated: 2022/07/13 20:08:45 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	num;
	void	*s;

	num = count * size;
	s = (void *)malloc(num);
	if (!s)
		return (NULL);
	else
		ft_bzero(s, num);
	return (s);
}
