#include "../includes/push_swap.h"

// checks if the passed arguments are valid numbers
int	is_args_valid(int ac, char **av)
{
	int	i;
	int len;

	while (ac-- > 1)
	{
		i = 0;
		len = strlen(av[ac]);
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
// pushing elemnts to the stack from last to first
void	fill_stack(int ac, char **av, stack **top)
{
    while (ac-- > 1)
        push(top, ft_atol(av[ac]));
}
void	fill_array(int ac, stack *top, int *arr)
{
	int min = -1000;
	int i = 0;
	while (i < ac - 1)
	{
		arr[i] = get_lowest_num2(top, min);
		min = arr[i];
		i++;
	}
}


void fill_index(stack **top, int *arr, int ac)
{
	stack *temp;
	int i = 0;

	temp = *top;
	while (temp)
	{
		while (i < ac-1)
		{
			if (temp->data == arr[i])
			{
				temp->index = i;

			}
			i++;
		}
		i = 0;
		temp = temp->next;
	}
}

void operations(int ac, stack **top, stack **b)
{
	if (ac == 2)
		sort_2_elements(top,'a');
	else if (ac == 3)
		sort_3_elements(top);
	else if(ac == 5)
		sort_5_elements(top);
	else if (ac > 5)
		sort2(top,b);
}
int	main(int ac, char **av)
{
    stack *top;

	stack *b;
	b = NULL;
    top = NULL;
	int *arr = malloc(sizeof(int)*(ac - 1));
	
    if(!is_args_valid(ac,av))
	{
        write(2, "Error\n", 6);
		return 0;
	}
    fill_stack(ac, av, &top);
	
	fill_array(ac,top, arr);
	fill_index(&top, arr, ac);
	operations(ac -1,&top, &b);
	// ft_printf("a : ");
	print_stack_data(top);
	// ft_printf("b : ");
	// print_stack_data(b);
	free_stack(top);
    free(arr);
	return 0;
}
