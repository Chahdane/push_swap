/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:24 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/19 15:37:51 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *top)
{
	t_stack	*ptr;

	ptr = top;
	while (ptr->next != NULL)
	{
		if (ptr->data < ptr->next->data)
			ptr = ptr->next;
		else
			return (0);
	}
	return (1);
}

void	sort_2_elements(t_stack **top, char ab)
{
	if ((*top)->data > (*top)->next->data)
		swap((*top), ab);
}

//this functions sorts a 3 num t_stack in a max of 2 moves :)
void	sort_3_elements(t_stack **top)
{
	int	a;
	int	b;
	int	c;

	a = (*top)->data;
	b = (*top)->next->data;
	c = (*top)->next->next->data;
	if (a > b && a < c)
	{
		swap((*top), 'a');
		sort_3_elements(top);
	}
	else if (a > b)
	{
		rotate(top, 'a');
		sort_3_elements(top);
	}
	else if (a < b && b > c)
	{
		reverse_rotate(top, 'a');
		sort_3_elements(top);
	}
	else if (a == b && b > c)
		reverse_rotate(top, 'a');
}

void	sort_3_in_a(t_stack **top)
{
	if (is_sorted(*top))
		return ;
	if ((*top)->data > (*top)->next->data
		&& (*top)->data < (*top)->next->next->data)
	{
		swap((*top), 'a');
		sort_3_in_a(top);
	}
	else if ((*top)->data > (*top)->next->data
		&& (*top)->data > (*top)->next->next->data)
	{
		swap((*top), 'a');
		sort_3_in_a(top);
	}
	else if ((*top)->data < (*top)->next->data
		&& (*top)->next->data > (*top)->next->next->data)
	{
		rotate(top, 'a');
		swap((*top), 'a');
		reverse_rotate(top, 'a');
		if ((*top)->data > (*top)->next->data)
			swap((*top), 'a');
	}
	else
		rotate(top, 'a');
}
