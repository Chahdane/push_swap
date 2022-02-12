/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:46 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/12 01:42:31 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// == PUSH OPERATIONS ==
void	push(t_stack **top, int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->data = data;
	new->next = *top;
	*top = new;
}

// pa pb
void	push_element(t_stack **from, t_stack **to, char ab)
{
	t_stack	*temp;

	temp = *from;
	if (ab == 'a' || ab == 'b')
		ft_putstr_fd("p", ab);
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

// == SWAP OPERATIONS ==
/* used to swap the first 2 elements in the t_stack (sa sb). */
void	swap(t_stack *top, char ab)
{
	int	temp;

	temp = top->data;
	if (!top || !top->next)
		return ;
	if (ab == 'a' || ab == 'b')
		ft_putstr_fd("s", ab);
	(top)->data = top->next->data;
	top->next->data = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	ft_putstr_fd("ss", '0');
	swap(a, '0');
	swap(b, '0');
}

void	free_t_stack(t_stack *top)
{
	t_stack	*tmp;

	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}
