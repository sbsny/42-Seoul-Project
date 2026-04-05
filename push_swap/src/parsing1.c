/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:47:01 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/06 11:48:59 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
	{
		sign *= -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += ((long long)*str++ - 48);
	}
	num *= sign;
	if (num < -2147483648 || num > 2147483647)
		return (2147483648);
	return (num);
}

int	has_no_duplicates(int *values, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
			if (values[i] == values[j])
				return (0);
	}
	return (1);
}

int	free_triple_strings(char ***str)
{
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			free(str[i][j]);
			str[i][j] = NULL;
		}
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
	return (0);
}
