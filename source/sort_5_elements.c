/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:25:23 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/19 15:39:26 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

int	get_lowest_num3(t_stack *top)
{
	int		res;
	t_stack	*temp;
	int		i;

	i = 0;
	res = top->data;
	temp = top;
	while (temp != NULL && i < 4)
	{
		if (res > temp->data)
			res = temp->data;
		temp = temp->next;
		i++;
	}
	return (res);
}

void	sort_5_elements(t_stack **top, t_stack **b, int ac)
{
	int		i;
	int		nb;

	i = 0;
	while (i < ac - 3)
	{
		nb = get_lowest_num3(*top);
		if (get_nb_pos(nb, *top) <= t_stack_len(*top) / 2)
			rotate_to_pos(top, get_distance(nb, *top), 'a');
		else
			rev_rotate_to_pos(top, get_distance(nb, *top), 'a');
		push_element(top, b, 'b');
		i++;
	}
	if (ac > 4)
		if ((*b)->data < (*b)->next->data)
			swap(*b, 'b');
	sort_3_elements(top);
	i = 0;
	while (i < ac - 3)
	{
		push_element(b, top, 'a');
		i++;
	}
}
