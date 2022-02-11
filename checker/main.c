/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:21:35 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/10 23:21:39 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare(char *s1, char *s2)
{
	if (s1[0] != s2[0] || s1[1] != s2[1] || s1[2] != s2[2])
		return (0);
	return (1);
}

int	stack_lenn(stack *top)
{
	stack	*temp;
	int	count;

	count = 0;
	temp = top;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	check_stack(stack *top, int len)
{
	stack	*temp;
	int	count;

	count = 1;
	temp = top;
	while (temp->next)
	{
        	if (temp->data > temp->next->data)
            		return (1);
        	count++;
        	temp = temp->next;
	}
	if (count == len)
		return (0);
	return (1);
}

void	op(char *buffer, stack **a, stack **b)
{
	while (buffer)
	{
        	if (compare(buffer, "pb\n") && stack_lenn(*a) > 0)
			push_element(a, b, '0');
		else if (compare(buffer, "pa\n") && stack_lenn(*b) > 0)
			push_element(b, a, '0');
		else if (compare(buffer, "sa\n") && stack_lenn(*a) > 1)
			swap(*a, '0');
		else if (compare(buffer, "sb\n") && stack_lenn(*b) > 1)
			swap(*b, '0');
		else if (compare(buffer, "ra\n") && stack_lenn(*a) > 1)
			rotate(a, '0');
		else if (compare(buffer, "rb\n") && stack_lenn(*b) > 1)
			rotate(b, '0');
		else if (compare(buffer, "rra") && stack_lenn(*a) > 1)
			reverse_rotate(a, '0');
		else if (compare(buffer, "rrb") && stack_lenn(*b) > 1)
			reverse_rotate(b, '0');
		free(buffer);
		buffer = get_next_line(0);
		if (!buffer)
			break ;
	}
}

int	main(int ac, char **av){
	char	*buffer;
	int	i;
	stack	*a;
	stack	*b;

	b = NULL
	a = NULL;
	i = 0;
	if (!is_args_valid(ac, av))
	{
		write(2, "Error\n", 6);
		return 0;
	}
	fill_stack(ac, av, &a);
	buffer = get_next_line(0);
	if (!buffer)
		return 0;
	op(buffer, &a ,&b);
	if (check_stack(a, ac - 1) == 0)
		ft_printf("\n\nOK\n\n");
	else
		ft_printf("\n\nKO\n\n");
	free_stack(a);
	free_stack(b);
}
