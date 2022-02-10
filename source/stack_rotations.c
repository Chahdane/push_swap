/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:51 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/10 23:23:00 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

/* used tp shift up all elements of stack a by 1.
	The first element becomes the last one */

void	rotate(stack **top, char ab)
{
	if (!top || !(*top)->next)
		return ;
	if (ab == 'a' || ab == 'b')
		ft_putstr_fd("r", ab);
	stack	*curr;
	stack	*last;

	curr = (*top)->next;
	last = (*top);
	while (last->next != NULL)
		last = last->next;
	last->next = *top;
	(*top)->next= NULL;
	(*top) = curr;
}
/* used tp shift down all elements of stack a by 1.
	The last element becomes the first one */

void	reverse_rotate(stack **top, char ab)
{
	stack	*before_last;
	stack	*last;

	if (!top || !(*top)->next)
		return ;
	if (ab == 'a' || ab == 'b')
		ft_putstr_fd("rr", ab);
	before_last = *top;
	while(before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	last->next = *top;
	before_last->next = NULL;
	*top = last;
}

// this function is used to do rr || rrr operations

void rr(stack **a, stack **b, char is_reverse)
{
	if (is_reverse == 'n')
	{
		ft_putstr_fd("rr", '0');
		rotate(a,'0');
		rotate(b,'0');
	}
	else if (is_reverse == 'y')
	{
		ft_putstr_fd("rrr", '0');
		reverse_rotate(a,'0');
		reverse_rotate(b,'0');
	}
}
