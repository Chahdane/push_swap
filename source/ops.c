#include "../includes/push_swap.h"

int get_lowest_num(stack *top)
{
	int res;
	res = top->data;
	stack *temp;

	temp = top;

	while (temp != NULL)
	{
		if (res > temp->data)
			res = temp->data;
		temp = temp->next;
	}
	return res;
}

int get_lowest_num2(stack *top, int min)
{
	int res;
	res = 2147483647;
	stack *temp;

	temp = top;
	while (temp != NULL)
	{
		if (res > temp->data && temp->data > min)
		{
			res = temp->data;
		//	temp = top;
		}
		temp = temp->next;
	}
	return res;
}

int get_biggest_num(stack *top)
{
	int res;
	res = top->data;
	stack *temp;

	temp = top;

	while (temp != NULL)
	{
		if (res < temp->data)
			res = temp->data;
		temp = temp->next;
	}
	return res;
}