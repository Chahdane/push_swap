
#include "../includes/push_swap.h"

int main(int ac , char **av){
    char *buffer;
    int i;
    stack *a;
    stack *b;

    b = NULL;
   a = NULL;

    i = 0;
    fill_stack(ac, av, &a);
    print_stack_data(a);
    while (1)
    {
        buffer = get_next_line(0);
        if (strcmp(buffer, "pa\n"))
            push_element(&b, &a, 'a');
        else if (strcmp(buffer, "pb\n"))
            push_element(&b, &a, 'b');
        else if (strcmp(buffer, "sa\n"))
            swap(a, 'a');
        else if (strcmp(buffer, "sb\n"))
            swap(b, 'b');
        else if (strcmp(buffer, "ra\n"))
            rotate(&a, 'a');
        else if (strcmp(buffer, "rb\n"))
            rotate(&b, 'b');
        else if (strcmp(buffer, "rra\n"))
            reverse_rotate(&a, 'a');
        else if (strcmp(buffer, "rrb\n"))
            reverse_rotate(&b, 'b');
    }
    ft_printf("done");
}