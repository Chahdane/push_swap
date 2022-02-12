/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:41 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/12 01:37:23 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_distance(int nb, t_stack *top)
{
	int		pos;
	int		pos_front;
	t_stack	*temp;

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
		return (pos_front);
	return (pos);
}

void	sort(t_stack **top, t_stack **b, int len, int div)
{
	int	index;
	int	i;
	int	nb;

	index = len / div;
	i = 0;
	nb = 0;
	while (t_stack_len(*top))
	{
		nb = find_nb_in_range(index, *top);
		if (get_nb_pos(nb, *top) <= t_stack_len(*top) / 2)
		{
			rotate_to_pos(top, get_distance(nb, *top), 'a');
			push_element(top, b, 'b');
			i++;
		}
		else
		{
			rev_rotate_to_pos(top, get_distance(nb, *top), 'a');
			push_element(top, b, 'b');
			i++;
		}
		if (i == len / div)
		{
			i = 0;
			index = index + (len / div);
		}
	}
	while (t_stack_len(*top))
		push_element(top, b, 'b');
}

void	sort2(t_stack **top, t_stack **b, int ac)
{
	int	pos;
	int	nb;

	pos = 0;
	nb = (*top)->data;
	sort(top, b, t_stack_len(*top), 6);
	if (ac > 400)
	{
		while (t_stack_len(*b))
			push_element(b, top, 'a');
		sort(top, b, t_stack_len(*top), 18);
	}
	while (t_stack_len(*b))
	{
		nb = get_biggest_num(*b);
		pos = get_nb_pos(nb, *b);
		if (pos <= t_stack_len(*b) / 2)
		{
			rotate_to_pos(b, get_distance(nb, *b), 'b');
			push_element(b, top, 'a');
		}
		else
		{
			rev_rotate_to_pos(b, get_distance(nb, *b), 'b');
			push_element(b, top, 'a');
		}
	}
}
