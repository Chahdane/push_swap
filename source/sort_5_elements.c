#include"../includes/push_swap.h"

void	sort_5_elements(stack **top)
{
	stack	*b;
	int		i;

	i = 0;
	b = NULL;
	push2_sort3(top, &b);
	while (i < 2)
	{
		if (b->data <= (*top)->data)
			push_element(&b, top, 'a');
		else if (b->data > (*top)->data)
		{
			if (b->data <= (*top)->next->data)
				push_to_pos2(top, &b);
			else if (b->data < (*top)->next->next->data)
				push_to_pos3(top, &b);
			else
				push_to_pos4(top, &b);
		}
		i++;
	}
}
/*  push 2 elemnts from A to B,
	then sort the 3 in the stack A */

void	push2_sort3(stack **top, stack **b)
{
	push_element(top, b, 'b');
	push_element(top, b, 'b');
	sort_3_elements(top);
}

/* push the first element of b to 2nd pos of a
	(1 -> a -> (2) -> b -> 3 -> c -> 4)  */

void	push_to_pos2(stack **top, stack **b)
{
	rotate(top, 'a');
	push_element(b, top, 'a');
	reverse_rotate(top, 'a');
}

/* push the first element of b to 3rd pos of a
	(1 -> a -> 2 -> b -> (3) -> c -> 4)  */

void	push_to_pos3(stack **top, stack **b)
{
	rotate(top, 'a');
	rotate(top, 'a');
	push_element(b, top, 'a');
	reverse_rotate(top, 'a');
	reverse_rotate(top, 'a');
}

/* push the first element of b to 4 pos of a
	(1 -> a -> 2 -> b -> 3 c -> (4))  */

void	push_to_pos4(stack **top, stack **b)
{
	push_element(b, top, 'a');
	rotate(top, 'a');
}
