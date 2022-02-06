#include "../includes/push_swap.h"

void push_b_to_a(stack **a, stack **b);
int stack_len(stack *top);
void rotate_to_pos(stack **top, int pos);
void rev_rotate_to_pos(stack **top , int pos);
void sort3(stack **top, stack **b, int ac);

int get_nb_pos(int nb, stack *top)
{
	int pos = 0;
	stack *temp;
	temp = top;
	while (temp->data != nb)
	{
		temp = temp->next;
		pos++;
	}
	return pos;
}

int get_distance(int nb, stack *top)
{
	int pos;
	int pos_front;
	stack *temp; 

	temp = top;
	pos = 0;
	while (temp->data != nb)
	{
		temp = temp->next;
		pos++;
	}
	pos_front = pos;
	pos = 0;
	while (temp)
	{
		temp = temp->next;
		pos++;
	}
	if (pos_front < pos)
		return pos_front;
	return pos;
}


void sort(stack **top, stack **b, int len)
{
	int index = len/5.5;
	int cnt = index;
	int i = 0;
	//ft_printf("index => %d\n",index);
	while (i < stack_len(*top))
	{
		if ((*top)->index < index)
		{
			push_element(top, b, 'b');
			i++;
		}
		else
		{
			rotate(top, 'a');
		}
		if (i == cnt)
		{
			i = 0;
			index = index + cnt;
			//ft_printf("index => %d\n",index);
		}
	}
	// while(stack_len(*top))
	// {
	// 	oo++;
	// 	ft_printf("%d",(*top)->index);
	// 	push_element(top, b, 'b');
	// }
}
// FIX THIS 
void sort2(stack **top, stack **b)
{
	int pos = 0;
	int nb = (*top)->data;
	sort(top, b, stack_len(*top));
	//print_stack_data(*b);
	while (stack_len(*b))
	{
		nb = get_biggest_num(*b);
		//ft_printf("nb =>>> %d\n",nb);
		pos = get_nb_pos(nb, *b);
		//ft_printf("pos =>>> %d\n",nb);
		if (pos <= stack_len(*b)/2)
		{
			rotate_to_pos(b, get_distance(nb, *b));
			push_element(b,top,'a');
		}
		else
		{
			rev_rotate_to_pos(b, get_distance(nb, *b));
			push_element(b,top,'a');
		}
		
	}

}
void rev_rotate_to_pos(stack **top , int pos)
{
	int i = 0;
	while (i < pos)
	{
		reverse_rotate(top, 'a');
		i++;
	}
}
void rotate_to_pos(stack **top,int pos)
{
	int i = 0;
	while (i < pos)
	{
		rotate(top, 'a');
		i++;
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