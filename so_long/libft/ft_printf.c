/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 06:04:30 by seonyun           #+#    #+#             */
/*   Updated: 2022/08/26 15:47:36 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	output(char format, va_list *ap)
{
	int	len;

	len = 0;
	if (format == '%')
		len += write(1, "%", 1);
	if (format == 'c')
		len += ft_putchar(va_arg(*ap, int));
	if (format == 's')
		len += ft_putstr(va_arg(*ap, char *));
	if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(*ap, int));
	if (format == 'u')
		len += ft_putnbr2(va_arg(*ap, unsigned int));
	if (format == 'p')
		len += ft_putptr(va_arg(*ap, unsigned long int));
	if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg(*ap, unsigned int), format);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		if (format[i] == '%')
		{
			i++;
			len += output(format[i], &ap);
		}
		i++;
	}
	va_end(ap);
	return (len);
}
