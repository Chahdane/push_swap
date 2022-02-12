/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:51 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/12 01:41:39 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* used tp shift up all elements of t_stack a by 1.
	The first element becomes the last one */

void	rotate(t_stack **top, char ab)
{
	t_stack	*last;
	t_stack	*curr;

	if (!top || !(*top)->next)
		return ;
	if (ab == 'a' || ab == 'b')
		ft_putstr_fd("r", ab);
	last = (*top);
	curr = (*top)->next;
	while (last->next != NULL)
		last = last->next;
	last->next = *top;
	(*top)->next = NULL;
	(*top) = curr;
}
/* used tp shift down all elements of t_stack a by 1.
	The last element becomes the first one */

void	reverse_rotate(t_stack **top, char ab)
{
	t_stack	*before_last;
	t_stack	*last;

	if (!top || !(*top)->next)
		return ;
	if (ab == 'a' || ab == 'b')
		ft_putstr_fd("rr", ab);
	before_last = *top;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	last->next = *top;
	before_last->next = NULL;
	*top = last;
}

// this function is used to do rr || rrr operations

void	rr(t_stack **a, t_stack **b, char is_reverse)
{
	if (is_reverse == 'n')
	{
		ft_putstr_fd("rr", '0');
		rotate(a, '0');
		rotate(b, '0');
	}
	else if (is_reverse == 'y')
	{
		ft_putstr_fd("rrr", '0');
		reverse_rotate(a, '0');
		reverse_rotate(b, '0');
	}
}
