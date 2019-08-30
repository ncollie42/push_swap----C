#include "header.h"

void	bot_push(t_stack *stack, t_node *node)
{
	if (node && stack)
	{
		if (!stack->top) 
		{
			stack->top = node;
			stack->bot = node;
		} 
		else
		{
			node->above = stack->bot;
			stack->bot->below = node;
			stack->bot = node;
		}
	}
}

void	pushInt(t_stack *stack, int num)
{
	bot_push(stack, newStackNode(num));
}

bool	isSorted(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->top;
	while(tmp->below)
	{
		if (tmp->num > tmp->below->num)
			return false;
		tmp = tmp->below;
	}
	return true;
}

void	verify(t_stack *A, t_stack *B)
{
	printf("%s\n", (!B->top && isSorted(A)) ? "OK" : "KO");
}