/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:25:23 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/14 17:48:42 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

void	sort_5_elements(t_stack **top, t_stack **b, int ac)
{
	int		i;
	int		nb;

	i = 0;
	while (i < ac -3)
	{
		nb = get_lowest_num(*top);
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
	while (t_stack_len(*b))
		push_element(b, top, 'a');
}
