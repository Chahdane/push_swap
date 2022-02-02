#include "../includes/push_swap.h"

void push_b_to_a(stack **a, stack **b);


int get_biggest_num(stack *top)
{
	int res;
	stack *temp;

	temp = top;

	while (temp != NULL)
	{
		if (res < temp->data)
			res = temp->data;
		temp = temp->next;
	}
	//exit(0);
	return res;
}

void sort(stack **top)
{
	stack *b;
	int nb;

	b = NULL;
	nb = get_biggest_num(*top);
	int i = 0;
	while ((*top)->data != nb && i < 50)
	{
		rotate(top, 'a');
		i++;
	}
	write(1, "hfgd\n", 1);
	print_stack_data(*top);
	push_element(top, &b, 'b');

	print_stack_data(*top);
	print_stack_data(b);
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