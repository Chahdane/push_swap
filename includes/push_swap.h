# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
# include <stdarg.h>

typedef struct stack
{
    int data;
    int index;
    struct stack *next;   
}   stack;

// sort_utls
void rev_rotate_to_pos(stack **top , int pos, char ab);
void rotate_to_pos(stack **top,int pos, char ab);
int stack_len(stack *top);
void push_b_to_a(stack **a, stack **b);
int get_nb_pos(int nb, stack *top);

//sort_utls2
int get_rev_pos(int nb, stack *top);
int get_distance(int nb, stack *top);
int get_last_in_index(int index, stack *top);
int	find_nb_in_range(int index, stack *top);
int r_rr(int index,int chunk_len, stack *top);
// push swap
void operations(int ac, stack **top, stack **b);
void fill_index(stack **top, int *arr, int ac);
void	fill_stack(int ac, char **av, stack **top);
int	is_args_valid(int ac, char **av);
void	fill_array(int ac, stack *top, int *arr);


int	ft_itoa(int n);
char    *get_next_line(int fd);
int	ft_putstr(char *str);
long	ft_atol(char *str);
void	print_stack_data(stack *top);
void	push(stack **top, int data);
int		is_sorted(stack *top);
void	free_stack(stack *top);
int	ft_printf(const char *str, ...);
void	ft_putstr_fd(char *str, char c);

void	swap(stack *top, char ab);
void	rotate(stack **top, char ab);
void	reverse_rotate(stack **top, char ab);
void	push_element(stack **from, stack **to, char ab);


void	sort_2_elements(stack **top, char ab);
void	sort_3_elements(stack **top);
void	sort_5_elements(stack **top);
void sort(stack **top, stack **b, int len, int div);
void sort2(stack **top, stack **b, int ac);

void push_5_to_a(stack **a, stack **b);

void	push2_sort3(stack **top, stack **b);
void	push_to_pos2(stack **top, stack **b);
void	push_to_pos3(stack **top, stack **b);
void	push_to_pos4(stack **top, stack **b);
void	push_to_last_pos(stack **top, stack **b);

int get_biggest_num(stack *top);
int get_lowest_num2(stack *top, int min);

#endif