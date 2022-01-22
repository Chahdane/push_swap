#include "../includes/push_swap.h"

void push_b_to_a(stack **a, stack **b);

void quick_sort(stack **top)
{
	int pivot;
	int count;
	stack *b;

	count = 0;
	b = NULL;
	pivot = (*top)->data;
	while (count < 10)
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
}
void quick_sort2(stack **top)
{
	while (!is_sorted(*top))
	{
		quick_sort(top);
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