/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:17:05 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/06 11:44:21 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_small_b(t_stack *a, t_stack *b, int size)
{
	if (size >= 2)
	{
		if (b->values[b->top_index] < b->values[b->top_index - 1])
			apply_operation("sb", a, b);
		if (size == 3)
		{
			if (!is_sorted(b, size, 1))
			{
				apply_operation("rb", a, b);
				apply_operation("sb", a, b);
				apply_operation("rrb", a, b);
				if (b->values[b->top_index] < b->values[b->top_index - 1])
					apply_operation("sb", a, b);
			}
			apply_operation("pa", a, b);
		}
		apply_operation("pa", a, b);
	}
	apply_operation("pa", a, b);
	return (1);
}

void	partition_b_to_a(t_stack *a, t_stack *b, int size, t_piv_cnt *piv_cnt)
{
	while (size-- > 0)
	{
		if (b->values[b->top_index] < piv_cnt->low_pivot)
		{
			apply_operation("rb", a, b);
			piv_cnt->rotate_b++;
		}
		else if (b->values[b->top_index] >= piv_cnt->high_pivot)
		{
			apply_operation("pa", a, b);
			piv_cnt->push_a++;
		}
		else
		{
			apply_operation("pa", a, b);
			piv_cnt->push_a++;
			apply_operation("ra", a, b);
			piv_cnt->rotate_a++;
		}
	}
}

int	move_b_to_a(t_stack *a, t_stack *b, int size)
{
	t_piv_cnt	piv_cnt;
	int			rrr_size;

	if (size <= 3)
		return (sort_small_b(a, b, size));
	piv_cnt = (t_piv_cnt){0, 0, 0, 0, 0, 0};
	set_pivots_from_sorted(b, size, &piv_cnt, 1);
	partition_b_to_a(a, b, size, &piv_cnt);
	move_a_to_b(a, b, (piv_cnt.push_a - piv_cnt.rotate_a));
	rrr_size = piv_cnt.rotate_a;
	while (rrr_size-- > 0)
		apply_dual_operation("rrr", a, b);
	move_a_to_b(a, b, piv_cnt.rotate_a);
	move_b_to_a(a, b, piv_cnt.rotate_b);
	return (1);
}
