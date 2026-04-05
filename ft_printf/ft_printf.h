/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:48:09 by seonyun           #+#    #+#             */
/*   Updated: 2022/08/26 15:47:36 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr2(unsigned int n);
int	ft_putnbr(int n);
int	ft_putptr2(unsigned long int n);
int	ft_putptr(unsigned long int n);
int	ft_puthex(unsigned int n, char format);
int	ft_putchar(char c);
int	ft_printf(const char *format, ...);

#endif