#include "../includes/push_swap.h"

int	is_sorted(stack *top)
{
	stack *ptr;

	ptr = top;
	while (ptr->next != NULL)
	{
		if (ptr->data < ptr->next->data)
			ptr = ptr->next;
		else
			return (0);
	}
	printf("sorted\n");
	return (1);
}

//this functions sorts a 3 num stack in a max of 2 moves :)

void sort_3_elements(stack **top)
{
	int a;
	int b;
	int c;

	a = (*top)->data;
	b = (*top)->next->data;
	c = (*top)->next->next->data;
	if (a > b && a < c)
	{
		swap((*top), 'a');
		sort_3_elements(top);
	}
	else if (a > b && a > c)
	{
		rotate(top, 'a');
		sort_3_elements(top);
	}
	else if (a < b && b > c)
	{
		reverse_rotate(top, 'a');
		sort_3_elements(top);
	}
}