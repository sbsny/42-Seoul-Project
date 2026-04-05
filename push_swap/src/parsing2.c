/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:55:10 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/25 01:23:53 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_tokens(char ***arg)
{
	int	i;
	int	j;
	int	cnt;

	i = -1;
	cnt = 0;
	while (arg[++i])
	{
		j = -1;
		while (arg[i][++j])
			cnt++;
	}
	return (cnt);
}

int	*free_and_return(int *values)
{
	free(values);
	values = NULL;
	return (0);
}

int	*build_stack_values(char ***arg, int size)
{
	int	*values;
	int	i[4];

	values = (int *)malloc(sizeof(int) * size);
	if (!values)
		return (0);
	i[0] = -1;
	i[2] = size;
	i[3] = 0;
	while (arg[++i[0]] && !i[3])
	{
		i[1] = -1;
		while (arg[i[0]][++i[1]] && !i[3])
		{
			if (ft_atoi(arg[i[0]][i[1]]) == 2147483648)
				i[3] = 1;
			else
				values[--i[2]] = (int)ft_atoi(arg[i[0]][i[1]]);
		}
	}
	free_triple_strings(arg);
	if (!has_no_duplicates(values, size) || i[3] == 1)
		return (free_and_return(values));
	return (values);
}

char	***split_arguments(char **argv, int argc)
{
	char	***arg;
	int		i;

	arg = (char ***)malloc(sizeof(char **) * argc);
	if (!arg)
		return (0);
	i = -1;
	while (++i < argc - 1)
	{
		arg[i] = ft_split(argv[i + 1]);
		if (!arg[i])
		{
			free_triple_strings(arg);
			return (NULL);
		}
	}
	arg[i] = 0;
	return (arg);
}

int	initialize_stacks(t_stack *a, t_stack *b, int size, char ***arg)
{
	a->values = build_stack_values(arg, size);
	if (!a->values)
		print_error_and_exit();
	b->values = (int *)malloc(sizeof(int) * size);
	if (!b->values)
		print_error_and_exit();
	a->top_index = size - 1;
	b->top_index = -1;
	return (1);
}
