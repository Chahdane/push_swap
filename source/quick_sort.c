#include "../includes/push_swap.h"

void push_b_to_a(stack **a, stack **b);
int is_a_sorted = 0;
void quick_sort(stack **top, int pivot)
{
	int count = 0;
	stack *b;
	b = NULL;
	if (is_sorted(*top))
		return ;
	//printf ("\n\n\npiv %d\n\n\n\n", pivot);
	while (count < 10 && !is_sorted(*top))
	{
		if ((*top)->data < pivot)
			push_element(top,&b, 'b');
		else
			rotate(top, 'a');
		count++;
	}
	if (is_sorted(*top))
	{
		is_a_sorted = 1;
	}
	push_b_to_a(top, &b);
	//print_stack_data(*top);
	if (is_sorted(*top) == 1)
		return ;
}

void quick_sort2(stack **top)
{
	int pv;
	stack *temp;

	temp = *top;

	while (!is_sorted(*top) && temp->next != NULL)
	{
		pv = temp->data;
		temp = temp->next;
		//printf ("pv : %d\n", pv);
		quick_sort(top, pv);
	}
	if (is_sorted(*top))
		return ;
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