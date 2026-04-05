/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 06:04:37 by seonyun           #+#    #+#             */
/*   Updated: 2022/08/26 15:56:17 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr2(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr2(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	return (ft_putnbr2(n) + len);
}

int	ft_putptr2(unsigned long int n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putptr2(n / 16);
		len += ft_putptr2(n % 16);
	}
	else if (n <= 9)
		len += ft_putchar(n + '0');
	else
		len += ft_putchar(n - 10 + 'a');
	return (len);
}

int	ft_putptr(unsigned long int n)
{
	int	len;

	len = 0;
	if (!n)
		len += write(1, "0x0", 3);
	else
	{
		len += write(1, "0x", 2);
		len += ft_putptr2(n);
	}
	return (len);
}

int	ft_puthex(unsigned int n, char format)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(n / 16, format);
		len += ft_puthex(n % 16, format);
	}
	else if (n <= 9)
		len += ft_putchar(n + '0');
	else if (format == 'x')
		len += ft_putchar(n - 10 + 'a');
	else if (format == 'X')
		len += ft_putchar(n - 10 + 'A');
	return (len);
}
