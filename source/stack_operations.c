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
	printf("\n");
}

void free_stack(stack *top)
{
	stack *tmp;

	while (top != NULL)
	{
    	tmp = top;
    	top = top->next;
    	free(tmp);
	}
}
// used to swap the first 2 elements in the stack (sa sb).
void	swap(stack *top, char ab)
{
	int temp;

	if (!top || !top->next)
		return ;
	if (ab == 'a' || ab == 'b')
		printf("s%c\n",ab);
	temp = top->data;
	(top)->data = top->next->data;
	top->next->data = temp;
}

// used tp shift up all elements of stack a by 1.
void rotate(stack *top, char ab)
{
	printf("r%c",ab);
	stack *curr;
	stack *last;

	curr = top->next;
	last = top;
	while (last != NULL)
		last = last->next;
	curr->next = NULL;
	last->next = top;
	top = curr->next;
}

void ss(stack *a, stack *b)
{
	printf("ss");
	swap(a,'0');
	swap(b,'0');
}

