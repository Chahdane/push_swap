/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:41 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/19 19:12:46 by achahdan         ###   ########.fr       */
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
	if (pos_front <= pos)
		return (pos_front);
	return (pos);
}

void	sort(t_stack **top, t_stack **b, int len, int div)
{
	int	index;
	int	i;
	int	nb;
	int	pos;

	index = len / div;
	i = 0;
	nb = 0;
	while (t_stack_len(*top))
	{
		nb = find_nb_in_range(index, *top);
		pos = get_nb_pos(nb, *top);
		if (pos <= t_stack_len(*top) / 2)
			rotate_to_pos(top, get_distance(nb, *top), 'a');
		push_element(top, b, 'b');
		i++;
		if (i == len / div)
		{
			i = 0;
			div += 2.99;
			len -= 3;
			index += (len / div);
		}
	}
}

void	sort_500(t_stack **top, t_stack **b)
{
	int	nb;
	int	index;
	int	i;

	i = 0;
	index = 497;
	sort(top, b, t_stack_len(*top), 5);
	while (t_stack_len(*b) - 2)
	{
		nb = get_nb_with_index(index,*b);
		if (get_nb_pos(get_nb_with_index(index, *b), *b) <= t_stack_len(*b) / 2)
			rotate_to_pos(b, get_distance(nb, *b), 'b');
		else
			rev_rotate_to_pos(b, get_distance(nb, *b), 'b');
		push_element(b, top, 'a');
		i++;
		if (i == 3)
		{
			sort_3_in_a(top);
			i = 0;
			index -= 3;
		}
	}
	push_2_sort(top, b);
}

void	sortt(t_stack **top, t_stack **b)
{
	int	nb;
	int	i;
	int	index;

	index = 97;
	i = 0;
	sort(top, b, t_stack_len(*top), 3);
	while (t_stack_len(*b) - 1)
	{
		nb = get_nb_with_index(index,*b);
		if (get_nb_pos(nb, *b) <= t_stack_len(*b) / 2)
			rotate_to_pos(b, get_distance(nb, *b), 'b');
		else
			rev_rotate_to_pos(b, get_distance(nb, *b), 'b');
		push_element(b, top, 'a');
		i++;
		if (i == 3)
		{
			sort_3_in_a(top);
			i = 0;
			index -= 3;
		}
	}
	push_element(b, top, 'a');
}

void	sort_all(t_stack **top, t_stack **b, int ac)
{
	int	nb;
	int	i;
	int	a;

	a = 3;
	i = 0;
	if (ac < 63)
		a = 1;
	sort(top, b, t_stack_len(*top), a);
	while (t_stack_len(*b))
	{
		nb = get_biggest_num(*b);
		if (get_nb_pos(nb, *b) <= t_stack_len(*b) / 2)
			rotate_to_pos(b, get_distance(nb, *b), 'b');
		else
			rev_rotate_to_pos(b, get_distance(nb, *b), 'b');
		push_element(b, top, 'a');
		i++;
	}
}
