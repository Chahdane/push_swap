/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 23:31:17 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/19 19:12:18 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_lowest_num(t_stack *top)
{
	int		res;
	t_stack	*temp;

	res = top->data;
	temp = top;
	while (temp != NULL)
	{
		if (res > temp->data)
			res = temp->data;
		temp = temp->next;
	}
	return (res);
}

int	get_lowest_num2(t_stack *top, int min)
{
	int		res;
	t_stack	*temp;

	res = 2147483647;
	temp = top;
	while (temp != NULL)
	{
		if (res > temp->data && temp->data > min)
			res = temp->data;
		temp = temp->next;
	}
	return (res);
}

int	get_biggest_num(t_stack *top)
{
	int		res;
	t_stack	*temp;

	res = top->data;
	temp = top;
	while (temp != NULL)
	{
		if (res < temp->data)
			res = temp->data;
		temp = temp->next;
	}
	return (res);
}

int	get_nb_with_index(int index, t_stack *top)
{
	t_stack	*temp;
	int		fst;
	int		lst;

	temp = top;
	while (temp)
	{
		if (temp->index >= index)
		{
			fst = temp->data;
			break ;
		}
		temp = temp->next;
	}
	while (temp)
	{
		if (temp->index >= index)
			lst = temp->data;
		temp = temp->next;
	}
	if (get_distance(fst, top) < get_distance(lst, top))
		return (fst);
	return (lst);
}

void	push_2_sort(t_stack **top, t_stack **b)
{
	push_element(b, top, 'a');
	push_element(b, top, 'a');
	if ((*top)->data > (*top)->next->data)
		swap(*top, 'a');
}
