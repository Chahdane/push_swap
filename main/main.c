/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:09 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/10 23:22:11 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
    stack *top;
	stack *b;
    int *arr;

	b = NULL;
    top = NULL;
    arr = malloc(sizeof(int)*(ac - 1));
    if(!is_args_valid(ac,av))
	{
        write(2, "Error\n", 6);
		free(arr);
		return 0;
	}
    fill_stack(ac, av, &top);
	fill_array(ac,top, arr);
	fill_index(&top, arr, ac);
	operations(ac -1,&top, &b);
	free_stack(top);
    free(arr);
	return 0;
}