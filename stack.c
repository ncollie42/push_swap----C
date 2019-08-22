#include "header.h"

void	swapNodes(t_node *first, t_node *second)
{
	t_node *tmp;

	tmp = first;
	first->above = second;
	first->below = second->below;
	second->above = tmp;
	second->below = first;
}

void	swapTop(t_stack *stack)
{
	if (stack->top && stack->top->below)
	{
		swapNodes(stack->top, stack->top->below);
		stack->top = stack->top->above;
	}
}