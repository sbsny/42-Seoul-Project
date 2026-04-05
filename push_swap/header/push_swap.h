/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 05:11:21 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/23 02:04:50 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*values;
	int		top_index;
}				t_stack;

typedef struct s_piv_cnt
{
	int		high_pivot;
	int		low_pivot;
	int		rotate_a;
	int		rotate_b;
	int		push_a;
	int		push_b;
}				t_piv_cnt;

long long		ft_atoi(const char *str);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *str);
void			print_error_and_exit(void);
int				free_triple_strings(char ***str);
char			***split_arguments(char **argv, int argc);
int				count_tokens(char ***arg);
int				*build_stack_values(char ***arg, int size);
int				has_no_duplicates(int *values, int size);
int				initialize_stacks(t_stack *a, t_stack *b, int size, char ***arg);

int				swap_top(t_stack *values);
int				push_stack(t_stack *from_stack, t_stack *to_stack);
int				rotate_or_reverse(int mode, t_stack *values);
void			apply_operation(char *op_name, t_stack *a, t_stack *b);
void			apply_dual_operation(char *op_name, t_stack *a, t_stack *b);

void			bubble_sort(int *array, int size);
int				is_sorted(t_stack *values, int size, int order_type);
void			set_pivots_from_sorted(t_stack *values, int size,
					t_piv_cnt *pivot, int order_type);

int				sort_small_a(t_stack *a, t_stack *b, int size);
int				sort_small_b(t_stack *a, t_stack *b, int size);
void			partition_a_to_b(t_stack *a, t_stack *b, int size,
					t_piv_cnt *pivot_count);
void			partition_b_to_a(t_stack *a, t_stack *b, int size,
					t_piv_cnt *pivot_count);
int				move_a_to_b(t_stack *a, t_stack *b, int size);
int				move_b_to_a(t_stack *a, t_stack *b, int size);
void			sort_three(t_stack *a, t_stack *b);
void			sort_four(t_stack *a, t_stack *b);
void			sort_five(t_stack *a, t_stack *b);
void			push_swap(t_stack *a, t_stack *b, int size);

#endif
