#include "../includes/push_swap.h"

void	push(stack **top, int data)
{
    stack   *new;

    new = malloc(sizeof(stack));
    new->data = data;
    new->next = *top;
    *top = new; 
}
//TODO : DELETE LATER
void print_stack_data(stack *top)
{
    stack *temp;

    temp = top;
    while (temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
}