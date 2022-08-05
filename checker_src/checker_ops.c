/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:31:31 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/19 19:09:12 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op3(char *buffer, t_stack **a, t_stack **b)
{
	if (compare(buffer, "ra\n"))
	{
		if (t_stack_lenn(*a) > 1)
			rotate(a, '0');
	}
	else if (compare(buffer, "rb\n"))
	{
		if (t_stack_lenn(*b) > 1)
			rotate(b, '0');
	}
	else if (compare(buffer, "rra"))
	{
		if (t_stack_lenn(*a) > 1)
			reverse_rotate(a, '0');
	}
	else if (compare(buffer, "rrb"))
	{
		if (t_stack_lenn(*b) > 1)
			reverse_rotate(b, '0');
	}
}

void	op2(char *buffer, t_stack **a, t_stack **b)
{
	if (compare(buffer, "pb\n"))
	{
		if (t_stack_lenn(*a) > 0)
			push_element(a, b, '0');
	}
	else if (compare(buffer, "pa\n"))
	{
		if (t_stack_lenn(*b) > 0)
			push_element(b, a, '0');
	}
	else if (compare(buffer, "sa\n"))
	{
		if (t_stack_lenn(*a) > 1)
			swap(*a, '0');
	}
	else if (compare(buffer, "ss\n"))
	{
		if (t_stack_lenn(*b) > 1 && t_stack_len(*b) > 1)
			ss(*a, *b);
	}
	else if (compare(buffer, "sb\n"))
	{
		if (t_stack_lenn(*b) > 1)
			swap(*b, '0');
	}
}

void	err(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	err2(t_stack *a)
{
	if (is_sorted(a))
		ft_printf("OK");
	exit(0);
}
