/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:09 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/14 17:45:02 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_t_stack_data(t_stack *top)
{
	t_stack	*temp;

	temp = top;
	while (temp)
	{
		ft_printf("%d ", temp->data);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*top;
	t_stack	*b;
	int		*arr;

	b = NULL;
	top = NULL;
	if (!is_args_valid(ac, av) || !fill_t_stack(ac, av, &top))
	{
		write(2, "Error\n", 6);
		free_t_stack(top);
		return (0);
	}
	arr = malloc(sizeof(int) * (ac - 1));
	fill_array(ac, top, arr);
	fill_index(&top, arr, ac);
	operations(ac - 1, &top, &b);
	free_t_stack(top);
	free(arr);
	return (0);
}
