#include "../includes/push_swap.h"

void push_b_to_a(stack **a, stack **b);
int get_last_elem(stack *top);

int get_pivot(stack *top)
{	
	return top->data;
}
void quick_sort(stack **top, int pivot)
{
	int count = 0;
	stack *b;
	b = NULL;

	while (count < 10 && !is_sorted(*top))
	{
		if ((*top)->data < pivot)
		{
			push_element(top,&b, 'b');
		}
		else
		{
			rotate(top, 'a');
		}
		count++;
	}
	push_b_to_a(top, &b);
	if (is_sorted(*top))
		return ;
	else 
	{
		pivot = get_pivot(*top);
		printf("pv = %d\n", pivot);
		quick_sort(top, pivot);
	}
}

int stack_len(stack *top)
{
	stack	*temp;
	int count;

	count = 0;
	temp = top;

	while (temp != NULL)
	{
    	count++;
		temp = temp->next;
	}
	return count;
}

void push_b_to_a(stack **a, stack **b)
{
	int b_len;
	int i;

	i = 0;
	b_len = stack_len(*b);
	while (i < b_len)
	{
		push_element(b,a, 'a');
		i++;
	}
}