/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:20:07 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/14 19:57:31 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct t_stack
{
	int				data;
	int				index;
	struct t_stack	*next;
}	t_stack;

// sort_utls
void	rev_rotate_to_pos(t_stack **top, int pos, char ab);
void	rotate_to_pos(t_stack **top, int pos, char ab);
int		t_stack_len(t_stack *top);
void	push_b_to_a(t_stack **a, t_stack **b);
int		get_nb_pos(int nb, t_stack *top);

//sort_utls2
int		get_rev_pos(int nb, t_stack *top);
int		get_distance(int nb, t_stack *top);
int		get_last_in_index(int index, t_stack *top);
int		find_nb_in_range(int index, t_stack *top);
int		r_rr(int index, int chunk_len, t_stack *top);
// push swap
void	operations(int ac, t_stack **top, t_stack **b);
void	fill_index(t_stack **top, int *arr, int ac);
int		fill_t_stack(int ac, char **av, t_stack **top);
int		is_args_valid(int ac, char **av);
void	fill_array(int ac, t_stack *top, int *arr);
int		ft_itoa(int n);
char	*get_next_line(int fd);
int		ft_putstr(char *str);
long	ft_atol(char *str);
void	print_t_stack_data(t_stack *top);
void	push(t_stack **top, int data);
int		is_sorted(t_stack *top);
void	free_t_stack(t_stack *top);
int		ft_printf(const char *str, ...);
void	ft_putstr_fd(char *str, char c);
void	swap(t_stack *top, char ab);
void	rotate(t_stack **top, char ab);
void	reverse_rotate(t_stack **top, char ab);
void	push_element(t_stack **from, t_stack **to, char ab);
void	sort_2_elements(t_stack **top, char ab);
void	sort_3_elements(t_stack **top);
void	sort_5_elements(t_stack **top, t_stack **b, int ac);
void	sort(t_stack **top, t_stack **b, int len, int div);
void	sort2(t_stack **top, t_stack **b, int ac);
void	push_5_to_a(t_stack **a, t_stack **b);
void	push2_sort3(t_stack **top, t_stack **b);
void	push_to_pos2(t_stack **top, t_stack **b);
void	push_to_pos3(t_stack **top, t_stack **b);
void	push_to_pos4(t_stack **top, t_stack **b);
void	push_to_last_pos(t_stack **top, t_stack **b);
int		get_biggest_num(t_stack *top);
int		get_lowest_num2(t_stack *top, int min);
int		get_lowest_num(t_stack *top);
int		ft_strlen(char *str);

#endif
