/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 23:31:17 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/12 01:37:23 by achahdan         ###   ########.fr       */
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
