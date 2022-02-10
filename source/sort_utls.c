/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:35 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/10 23:22:37 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

void rev_rotate_to_pos(stack **top , int pos, char ab)
{
	int i = 0;
	while (i < pos)
	{
		reverse_rotate(top, ab);
		i++;
	}
}
void rotate_to_pos(stack **top,int pos, char ab)
{
	int i = 0;
	while (i < pos)
	{
		rotate(top, ab);
		i++;
	}
}

int stack_len(stack *top)
{
	stack	*temp;
	int count;

	count = 0;
	temp = top;

	while (temp != NULL)
	{
    	count++;
		temp = temp->next;
	}
	return count;
}

int get_nb_pos(int nb, stack *top)
{
	int pos = 0;
	stack *temp;
	temp = top;
	while (temp->data != nb)
	{
		temp = temp->next;
		pos++;
	}
	return pos;
}

int	find_nb_in_range(int index, stack *top)
{
	stack *temp;
	int ret;

	ret = -1;
	temp = top;
	while (temp)
	{
		if(temp->index <= index)
		{
			ret = temp->data;
			return ret;
		}
		temp = temp->next;
	}
	return ret;
}
