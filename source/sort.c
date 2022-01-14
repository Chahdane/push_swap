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

void sort_3_elements(stack **top)
{
	if ((*top)->data > (*top)->next->data)
		swap((*top), 'a');
	else rotate(top, 'a');
}