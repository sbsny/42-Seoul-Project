/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:09:40 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/06 11:44:33 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_top(t_stack *values)
{
	int	tmp;

	if (values->top_index < 1)
		return (0);
	else
	{
		tmp = values->values[values->top_index];
		values->values[values->top_index] = values->values[values->top_index - 1];
		values->values[values->top_index - 1] = tmp;
	}
	return (1);
}

int	push_stack(t_stack *pop, t_stack *push)
{
	if (pop->top_index == -1)
		return (0);
	else
	{
		push->top_index++;
		push->values[push->top_index] = pop->values[pop->top_index];
		pop->top_index--;
	}
	return (1);
}

int	rotate_or_reverse(int i, t_stack *values)
{
	int	tmp;
	int	idx;

	if (values->top_index < 1)
		return (0);
	else if (i == 0)
	{
		tmp = values->values[values->top_index];
		idx = values->top_index + 1;
		while (--idx > 0)
			values->values[idx] = values->values[idx - 1];
		values->values[0] = tmp;
	}
	else if (i == 1)
	{
		tmp = values->values[0];
		idx = -1;
		while (++idx < values->top_index)
			values->values[idx] = values->values[idx + 1];
		values->values[values->top_index] = tmp;
	}
	return (1);
}

void	apply_operation(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(str, "sa") && swap_top(a))
		write(1, "sa\n", 3);
	else if (!ft_strcmp(str, "sb") && swap_top(b))
		write(1, "sb\n", 3);
	else if (!ft_strcmp(str, "ss") && swap_top(a) && swap_top(b))
		write(1, "ss\n", 3);
	else if (!ft_strcmp(str, "pa") && push_stack(b, a))
		write(1, "pa\n", 3);
	else if (!ft_strcmp(str, "pb") && push_stack(a, b))
		write(1, "pb\n", 3);
	else if (!ft_strcmp(str, "ra") && rotate_or_reverse(0, a))
		write(1, "ra\n", 3);
	else if (!ft_strcmp(str, "rb") && rotate_or_reverse(0, b))
		write(1, "rb\n", 3);
	else if (!ft_strcmp(str, "rr") && rotate_or_reverse(0, a) && rotate_or_reverse(0, b))
		write(1, "rr\n", 3);
	else if (!ft_strcmp(str, "rra") && rotate_or_reverse(1, a))
		write(1, "rra\n", 4);
	else if (!ft_strcmp(str, "rrb") && rotate_or_reverse(1, b))
		write(1, "rrb\n", 4);
	else if (!ft_strcmp(str, "rrr") && rotate_or_reverse(1, a) && rotate_or_reverse(1, b))
		write(1, "rrr\n", 4);
}

void	apply_dual_operation(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(str, "ss") && a->top_index >= 1 && b->top_index < 1)
		apply_operation("sa", a, b);
	else if (!ft_strcmp(str, "ss") && a->top_index < 1 && b->top_index >= 1)
		apply_operation("sb", a, b);
	else if (!ft_strcmp(str, "ss") && a->top_index >= 1 && b->top_index >= 1)
		apply_operation("ss", a, b);
	if (!ft_strcmp(str, "rr") && a->top_index >= 1 && b->top_index < 1)
		apply_operation("ra", a, b);
	else if (!ft_strcmp(str, "rr") && a->top_index < 1 && b->top_index >= 1)
		apply_operation("rb", a, b);
	else if (!ft_strcmp(str, "rr") && a->top_index >= 1 && b->top_index >= 1)
		apply_operation("rr", a, b);
	if (!ft_strcmp(str, "rrr") && a->top_index >= 1 && b->top_index < 1)
		apply_operation("rra", a, b);
	else if (!ft_strcmp(str, "rrr") && a->top_index < 1 && b->top_index >= 1)
		apply_operation("rrb", a, b);
	else if (!ft_strcmp(str, "rrr") && a->top_index >= 1 && b->top_index >= 1)
		apply_operation("rrr", a, b);
}
