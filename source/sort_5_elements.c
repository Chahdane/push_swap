#include"../includes/push_swap.h"
void sort_5_elements(stack **top)
{
	stack *b;
	int i;

	i = 0;
	b = NULL;
	push2_sort3(top, &b);
	while (i < 2)
	{
		if (b->data <= (*top)->data)						//insert at first pos
			push_element(&b, top, 'a');
		else if (b->data > (*top)->data)					
		{
			if (b->data <= (*top)->next->data)				// 2nd pos
				push_to_pos2(top, &b);
			else if (b->data < (*top)->next->next->data)	// 3rd pos
				push_to_pos3(top, &b);
			else 											//last pos
				push_to_pos4(top, &b);
		}
		i++;
	}
}
// pushs 2 elemnts to stack B, then sort the 3 in the stack A
void	push2_sort3(stack **top, stack **b)
{
	push_element(top, b, 'b');
	push_element(top, b, 'b');
	sort_3_elements(top);
}

// push an element to 2nd pos (1 -> a -> (2) -> b -> 3 c -> 4) 

void	push_to_pos2(stack **top, stack **b)
{
	rotate(top, 'a');
	push_element(b,top,'a');
	reverse_rotate(top, 'a');
}

// push an element to 2nd pos (1 -> a -> 2 -> b -> (3) c -> 4) 

void	push_to_pos3(stack **top , stack **b)
{
	rotate(top, 'a');
	rotate(top, 'a');
	push_element(b,top,'a');
	reverse_rotate(top, 'a');
	reverse_rotate(top, 'a');
}
// push an element to 2nd pos (1 -> a -> 2 -> b -> 3 c -> (4)) 

void	push_to_pos4(stack **top, stack **b)
{
	push_element(b,top,'a');
	rotate(top, 'a');
}
