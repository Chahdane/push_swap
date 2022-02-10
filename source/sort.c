/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:41 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/10 23:22:42 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int get_distance(int nb, stack *top)
{
	int pos;
	int pos_front;
	stack *temp; 

	temp = top;
	pos = 0;
	while (temp->data != nb)
	{
		temp = temp->next;
		pos++;
	}
	pos_front = pos;
	pos = 0;
	while (temp)
	{
		temp = temp->next;
		pos++;
	}
	if (pos_front < pos)
		return pos_front;
	return pos;
}

void sort(stack **top, stack **b, int len, int div)
{
	int index = len/div;
	int nb = 0;
	int i = 0;
	while (i < stack_len(*top))
	{
		nb = find_nb_in_range(index, *top);
		if (get_nb_pos(nb, *top) < stack_len(*top)/2)
		{
			rotate_to_pos(top, get_distance(nb, *top),'a');
			push_element(top, b, 'b');
			i++;
		}
		else
		{
			rev_rotate_to_pos(top, get_distance(nb, *top), 'a');
			push_element(top, b, 'b');
			i++;
		}
		if (i == len/div)
		{
			i = 0;
			index = index + len/div;
		}
	}
	while(stack_len(*top))
		push_element(top, b, 'b');
}

// FIX THIS 
void sort2(stack **top, stack **b, int ac)
{
	int pos = 0;
	int nb = (*top)->data;
	sort(top, b, stack_len(*top),6);
	if (ac > 400)
	{
		while (stack_len(*b))
			push_element(b, top, 'a');
		sort(top, b, stack_len(*top),18);
	}
	while (stack_len(*b))
	{
		nb = get_biggest_num(*b);
		pos = get_nb_pos(nb, *b);
		if (pos <= stack_len(*b)/2)
		{
			rotate_to_pos(b, get_distance(nb, *b),'b');
			push_element(b,top,'a');
		}
		else
		{
			rev_rotate_to_pos(b, get_distance(nb, *b), 'b');
			push_element(b,top,'a');
		}
	}
}
