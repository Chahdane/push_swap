/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:46 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/10 23:22:47 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

// == PUSH OPERATIONS ==

void	push(stack **top, int data)
{
    stack	*new;

    new = malloc(sizeof(stack));
    new->data = data;
    new->next = *top;
    *top = new; 
}

// pa pb

void	push_element(stack **from, stack **to, char ab)
{
	stack *temp;
	if (ab == 'a' || ab == 'b')
		ft_putstr_fd("p", ab);
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

// == SWAP OPERATIONS ==

/* used to swap the first 2 elements in the stack (sa sb). */

void	swap(stack *top, char ab)
{
	int	temp;

	if (!top || !top->next)
		return ;
	if (ab == 'a' || ab == 'b')
		ft_putstr_fd("s", ab);
	temp = top->data;
	(top)->data = top->next->data;
	top->next->data = temp;
}

void ss(stack *a, stack *b)
{
	ft_putstr_fd("ss", '0');
	swap(a,'0');
	swap(b,'0');
}

//TODO : DELETE LATER
void	print_stack_data(stack *top)
{
    stack *temp;

    temp = top;
    while (temp != NULL)
    {
        ft_printf("%d ",temp->data);
		//ft_printf("%d ", temp->index);
        temp = temp->next;
    }
	ft_printf("\n");
}

void	free_stack(stack *top)
{
	stack	*tmp;

	while (top != NULL)
	{
    	tmp = top;
    	top = top->next;
    	free(tmp);
	}
}