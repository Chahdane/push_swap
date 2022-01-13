#include <stdio.h>
#include "../includes/push_swap.h"
// checks if the passed arguments are valid numbers
int	is_args_valid(int ac, char **av)
{
	while (ac-- > 1)
    	if (av[ac][0] < '0' || av[ac][0] > '9')
        	return (0);
    return (1);
}
// pushing elemnts to the stack from last to first
void	fill_stack(int ac, char **av, stack **top)
{
    while (ac-- > 1)
        push(top, ft_atoi(av[ac]));
}

int	main(int ac, char **av)
{
    stack *top;

    top = NULL;
    if(!is_args_valid(ac,av))
        return 0;
    fill_stack(ac, av, &top);
    print_stack_data(top);
    return 0;
}
