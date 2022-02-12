/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_elms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:43:57 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/12 01:50:11 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

void	sort_5_elements(t_stack **top)
{
	t_stack	*b;
	int		i;
    int nb = -88889;
	i = -1;
	b = NULL;
	while(t_stack_len(*top) > 3)
    {
        nb = get_lowest_num2(*top, nb);
        rotate_to_pos(&b, get_distance(nb, *top), 'a');
        push_element(top, &b, 'b');
    }
	sort_3_elements(top);
    push_element(&b, top, 'a');
    push_element(&b, top, 'a');
}