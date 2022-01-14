#include "../includes/push_swap.h"

void	push(stack **top, int data)
{
    stack   *new;

    new = malloc(sizeof(stack));
    new->data = data;
    new->next = *top;
    *top = new; 
}

void push_element(stack **from, stack **to, char ab)
{
	stack *temp;
	if (ab == 'a' || ab == 'b')
		printf("p%c\n",ab); 
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
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

/* used tp shift up all elements of stack a by 1.
	The first element becomes the last one */

void	rotate(stack **top, char ab)
{
	if (!top || !(*top)->next)
		return ;
	if (ab == 'a' || ab == 'b')
		printf("r%c\n",ab);
	stack *curr;
	stack *last;

	curr = (*top)->next;
	last = (*top);
	while (last->next != NULL)
		last = last->next;
	last->next = *top;
	(*top)->next= NULL;
	(*top) = curr;
}
/* used tp shift down all elements of stack a by 1.
	The last element becomes the first one */

void	reverse_rotate(stack **top, char ab)
{
	stack *before_last;
	stack *last;

	if (!top || !(*top)->next)
		return ;
	if (ab == 'a' || ab == 'b')
		printf("rr%c\n",ab);
	before_last = *top;
	while(before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	last->next = *top;
	before_last->next = NULL;
	*top = last;
}

// this function is used to do rr || rrr operations

void rr(stack **a, stack **b, char is_reverse)
{
	if (is_reverse == 'n')
	{
		printf("rr");
		rotate(a,'0');
		rotate(b,'0');
	}
	else if (is_reverse == 'y')
	{
		printf("rr");
		reverse_rotate(a,'0');
		reverse_rotate(b,'0');
	}
}

void ss(stack *a, stack *b)
{
	printf("ss");
	swap(a,'0');
	swap(b,'0');
}
