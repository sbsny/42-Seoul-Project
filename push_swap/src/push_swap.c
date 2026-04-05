/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:27:09 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/06 12:00:44 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b)
{
	int	i;
	int	*values;

	i = a->top_index;
	values = a->values;
	if (values[i] < values[i - 2] && values[i - 1] > values[i - 2])
	{
		apply_operation("sa", a, b);
		apply_operation("ra", a, b);
	}
	else if (values[i] > values[i - 1] && values[i] < values[i - 2])
		apply_operation("sa", a, b);
	else if (values[i] < values[i - 1] && values[i] > values[i - 2])
		apply_operation("rra", a, b);
	else if (values[i] > values[i - 1] && values[i - 1] < values[i - 2])
		apply_operation("ra", a, b);
	else if (values[i] > values[i - 1] && values[i - 1] > values[i - 2])
	{
		apply_operation("ra", a, b);
		apply_operation("sa", a, b);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	if (!is_sorted(a, 4, 0))
	{
		if (a->values[a->top_index] > a->values[a->top_index - 1])
			apply_operation("sa", a, b);
		apply_operation("pb", a, b);
		if (a->values[a->top_index] > a->values[a->top_index - 1])
			apply_operation("sa", a, b);
		apply_operation("pb", a, b);
		if (a->values[a->top_index] > a->values[a->top_index - 1] && \
			b->values[b->top_index] < b->values[b->top_index - 1])
			apply_operation("ss", a, b);
		else if (a->values[a->top_index] > a->values[a->top_index - 1])
			apply_operation("sa", a, b);
		else if (b->values[b->top_index] < b->values[b->top_index - 1])
			apply_operation("sb", a, b);
		apply_operation("pa", a, b);
		if (a->values[a->top_index] > a->values[a->top_index - 1])
			apply_operation("sa", a, b);
		apply_operation("pa", a, b);
		if (a->values[a->top_index] > a->values[a->top_index - 1])
			apply_operation("sa", a, b);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	i;
	int	array[5];

	if (!is_sorted(a, 5, 0))
	{
		i = -1;
		while (++i < 5)
			array[i] = a->values[a->top_index - i];
		bubble_sort(array, 5);
		while (i-- > 0)
		{
			if (a->values[a->top_index] <= array[1])
				apply_operation("pb", a, b);
			else
				apply_operation("ra", a, b);
		}
		sort_three(a, b);
		if (b->values[b->top_index] < b->values[b->top_index - 1])
			apply_operation("sb", a, b);
		apply_operation("pa", a, b);
		apply_operation("pa", a, b);
	}
}

void	push_swap(t_stack *a, t_stack *b, int size)
{
	if (is_sorted(a, size, 0))
		return ;
	if (size == 2)
	{
		if (a->values[a->top_index] > a->values[a->top_index - 1])
			apply_operation("sa", a, b);
	}
	else if (size == 3)
		sort_three(a, b);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		move_a_to_b(a, b, size);
	free(a->values);
	a->values = NULL;
	free(b->values);
	b->values = NULL;
}

int	main(int argc, char **argv)
{
	char	***arg;
	int		size;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
	arg = split_arguments(argv, argc);
	if (!arg)
		print_error_and_exit();
	size = count_tokens(arg);
	initialize_stacks(&a, &b, size, arg);
	push_swap(&a, &b, size);
	return (0);
}
