/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:16:21 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/06 11:44:21 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_small_a(t_stack *a, t_stack *b, int size)
{
	if (size == 4)
		sort_four(a, b);
	else if (size >= 2)
	{
		if (a->values[a->top_index] > a->values[a->top_index - 1])
			apply_operation("sa", a, b);
		if (size == 3 && !is_sorted(a, size, 0))
		{
			apply_operation("ra", a, b);
			apply_operation("sa", a, b);
			apply_operation("rra", a, b);
			if (a->values[a->top_index] > a->values[a->top_index - 1])
				apply_operation("sa", a, b);
		}
	}
	return (1);
}

void	partition_a_to_b(t_stack *a, t_stack *b, int size, t_piv_cnt *piv_cnt)
{
	while (size-- > 0)
	{
		if (a->values[a->top_index] > piv_cnt->high_pivot)
		{
			apply_operation("ra", a, b);
			piv_cnt->rotate_a++;
		}
		else if (a->values[a->top_index] <= piv_cnt->low_pivot)
		{
			apply_operation("pb", a, b);
			piv_cnt->push_b++;
		}
		else
		{
			apply_operation("pb", a, b);
			piv_cnt->push_b++;
			apply_operation("rb", a, b);
			piv_cnt->rotate_b++;
		}
	}
}

int	move_a_to_b(t_stack *a, t_stack *b, int size)
{
	t_piv_cnt	piv_cnt;
	int			rrr_size;

	if (size <= 4)
		return (sort_small_a(a, b, size));
	piv_cnt = (t_piv_cnt){0, 0, 0, 0, 0, 0};
	set_pivots_from_sorted(a, size, &piv_cnt, 0);
	partition_a_to_b(a, b, size, &piv_cnt);
	rrr_size = piv_cnt.rotate_b;
	while (rrr_size-- > 0)
		apply_dual_operation("rrr", a, b);
	move_a_to_b(a, b, piv_cnt.rotate_a);
	move_b_to_a(a, b, piv_cnt.rotate_b);
	move_b_to_a(a, b, piv_cnt.push_b - piv_cnt.rotate_b);
	return (1);
}
