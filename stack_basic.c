#include "header.h"

void	push(t_stack *stack, t_node *node)
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
			node->below = stack->top;
			stack->top->above = node;
			stack->top = node;
		}
	}
}

t_node	*pop(t_stack *stack)
{
	t_node *tmp;

	tmp = NULL;
	if (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->below;
		tmp->below = NULL;
		tmp->above = NULL;
	}
	return tmp;
}

t_stack *newStack()
{
	t_stack *tmp;

	tmp = malloc(sizeof(t_stack));
	*tmp = (t_stack){NULL, NULL};
	return tmp;
}

static t_node *newStackNode(int num)
{
	t_node *tmp;

	tmp = malloc(sizeof(t_node));
	*tmp = (t_node){num, NULL, NULL};
	return tmp;
}