#include "../includes/push_swap.h"

void push_b_to_a(stack **a, stack **b);
int stack_len(stack *top);
void rotate_to_pos(stack **top, int pos, char ab);
void rev_rotate_to_pos(stack **top , int pos, char ab);
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

int get_last_in_index(int index, stack *top)
{
	stack *temp;
	int ret;

	ret = -1;
	temp = top;
	while (temp)
	{
		if(temp->index <= index)
			ret = temp->data;
		temp = temp->next;
	}
	return ret;
}

int	find_nb_in_range(int index, stack *top)
{
	stack *temp;
	int ret;

	ret = -1;
	temp = top;
	while (temp)
	{
		if(temp->index <= index)
		{
			ret = temp->data;
			return ret;
		}
		temp = temp->next;
	}
	return ret;
}

int r_rr(int index,int chunk_len, stack *top)
{
	int count;
	int i;
	stack *temp;

	temp = top;
	count = 0;
	i = 0;

	while (i < stack_len(top)/2)
	{
		if (temp->index < index)
			count++;
		temp = temp->next;
		i++;
	}
	if (count > chunk_len/2)
		return 1;
	return 0;
}

void sort(stack **top, stack **b, int len, int div)
{
	int index = len/div;
	int nb = 0;
	int pos = 0;
	int last = 0;
	int i = 0;
	int to_find = -1;
	while (i < stack_len(*top))
	{
		nb = find_nb_in_range(index, *top);
		last = get_last_in_index(index, *top);
		to_find = nb;
		if (get_nb_pos(nb, *top) >= get_nb_pos(last, *top))
			to_find = last;
		pos = get_nb_pos(to_find, *top);
		if (pos < stack_len(*top)/2)
		{
			rotate_to_pos(top, get_distance(nb, *top),'a');
			push_element(top, b, 'b');
			i++;
		}
		else
		{
			rev_rotate_to_pos(top, get_distance(nb, *top),'a');
			push_element(top, b, 'b');
			i++;
		}
		if (i == len/div)
		{
			i = 0;
			index = index + len/div;
		}
	}
	while(stack_len(*top))
		push_element(top, b, 'b');
}

// FIX THIS 
void sort2(stack **top, stack **b)
{
	int pos = 0;
	int nb = (*top)->data;
	sort(top, b, stack_len(*top),6);
	while (stack_len(*b))
		push_element(b, top, 'a');
	sort(top, b, stack_len(*top),18);
	while (stack_len(*b))
	{
		nb = get_biggest_num(*b);
		pos = get_nb_pos(nb, *b);
		if (pos <= stack_len(*b)/2)
		{
			rotate_to_pos(b, get_distance(nb, *b),'b');
			push_element(b,top,'a');
		}
		else
		{
			rev_rotate_to_pos(b, get_distance(nb, *b), 'b');
			push_element(b,top,'a');
		}
	}
}


void rev_rotate_to_pos(stack **top , int pos, char ab)
{
	int i = 0;
	while (i < pos)
	{
		reverse_rotate(top, ab);
		i++;
	}
}
void rotate_to_pos(stack **top,int pos, char ab)
{
	int i = 0;
	while (i < pos)
	{
		rotate(top, ab);
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