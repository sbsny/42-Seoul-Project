/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunglee <sunglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:27:51 by sunglee           #+#    #+#             */
/*   Updated: 2023/02/06 13:27:56 by sunglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned char	*p;

	p = (unsigned char *) b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}
