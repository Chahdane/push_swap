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

void sort_2_elements(stack **top, char ab)
{
	if ((*top)->data > (*top)->next->data)
		swap((*top), ab);
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
//TODO : optimise it
void sort_5_elements(stack **top)
{
	stack *b;
	int i;

	i = 0;
	b = NULL;
	push_element(top, &b, 'b');
	push_element(top, &b, 'b');
	sort_3_elements(top);
	while (i < 2)
	{
		if (b->data <= (*top)->data)						//insert at first pos
			push_element(&b, top, 'a');
		else if (b->data > (*top)->data)					
		{
			if (b->data <= (*top)->next->data)				// 2nd pos
			{
				rotate(top, 'a');
				push_element(&b,top,'a');
				reverse_rotate(top, 'a');
			}
			else if (b->data < (*top)->next->next->data)	// 3rd pos
			{
				rotate(top, 'a');
				rotate(top, 'a');
				push_element(&b,top,'a');
				reverse_rotate(top, 'a');
				reverse_rotate(top, 'a');
			}
			else 											//last pos
			{
				push_element(&b,top,'a');
				rotate(top, 'a');
			}
		}
		i++;
	}
}