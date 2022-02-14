/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:17 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/14 19:57:08 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_args_valid(int ac, char **av)
{
	int	i;
	int	len;

	while (ac-- > 1)
	{
		i = 0;
		len = ft_strlen(av[ac]);
		if (len > 11)
			return (0);
		if (ft_atol(av[ac]) < -2147483648 || ft_atol(av[ac]) > 2147483647)
			return (0);
		if (av[ac][i] == '-' || av[ac][i] == '+')
			if (av[ac][i] == '-')
				i++;
		if (av[ac][i] < '0' || av[ac][i] > '9')
			return (0);
	}
	return (1);
}

// pushing elemnts to the t_stack from last to first
int	fill_t_stack(int ac, char **av, t_stack **top)
{
	t_stack	*temp;

	while (ac -- > 1)
	{
		temp = *top;
		while (temp)
		{
			if (temp->data == ft_atol(av[ac]))
				return (0);
			temp = temp->next;
		}
		push(top, ft_atol(av[ac]));
	}
	return (1);
}

void	fill_array(int ac, t_stack *top, int *arr)
{
	int	min;
	int	i;

	min = -2147483648;
	i = 0;
	while (i < ac - 1)
	{
		arr[i] = get_lowest_num2(top, min);
		min = arr[i];
		i++;
	}
}

void	fill_index(t_stack **top, int *arr, int ac)
{
	t_stack	*temp;
	int		i;

	temp = *top;
	i = 0;
	while (temp)
	{
		while (i < ac - 1)
		{
			if (temp->data == arr[i])
				temp->index = i;
			i++;
		}
		i = 0;
		temp = temp->next;
	}
}

void	operations(int ac, t_stack **top, t_stack **b)
{
	if (ac == 2)
		sort_2_elements(top, 'a');
	else if (ac == 3)
		sort_3_elements(top);
	else if (ac == 5 || ac == 4)
		sort_5_elements(top, b, ac);
	else if (ac > 5)
		sort2(top, b, ac);
}
