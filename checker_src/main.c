/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:21:35 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/19 19:42:48 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare(char *s1, char *s2)
{
	if (s1[0] != s2[0] || s1[1] != s2[1] || s1[2] != s2[2])
		return (0);
	return (1);
}

int	t_stack_lenn(t_stack *top)
{
	t_stack	*temp;
	int		count;

	count = 0;
	temp = top;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	check_t_stack(t_stack *top, int len)
{
	t_stack	*temp;
	int		count;

	count = 1;
	temp = top;
	while (temp && temp->next)
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

void	op(char *buffer, t_stack **a, t_stack **b)
{
	while (buffer)
	{
		if (compare(buffer, "pb\n") || compare(buffer, "pa\n")
			|| compare(buffer, "sa\n") || compare(buffer, "ss\n")
			|| compare(buffer, "sb\n"))
			op2(buffer, a, b);
		else if (compare(buffer, "ra\n") || compare(buffer, "rb\n")
			|| compare(buffer, "rra\n") || compare(buffer, "rrbs\n"))
			op3(buffer, a, b);
		else
		{
			free(buffer);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(buffer);
		buffer = get_next_line(0);
		if (!buffer)
			break ;
	}
}

int	main(int ac, char **av)
{
	char	*buffer;
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	if (ac < 2)
		return (0);
	if (!is_args_valid(ac, av) || !fill_t_stack(ac, av, &a))
		err();
	buffer = get_next_line(0);
	if (!buffer)
		err2(a);
	op(buffer, &a, &b);
	if (check_t_stack(a, ac - 1) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (t_stack_len(a) > 0)
		free_t_stack(a);
	if (t_stack_len(b))
		free_t_stack(b);
	return (0);
}
