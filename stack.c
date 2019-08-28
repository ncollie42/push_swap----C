#include "header.h"

static void	swapNodes(t_node *first, t_node *second)
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

void	print(t_stack *stack)
{
	t_node *tmp = stack->top;

	while(tmp)
	{
		printf("%d -", tmp->num);
		tmp = tmp->below;
	}
}

static t_node *newStackNode(int num)
{
	t_node *tmp;

	tmp = malloc(sizeof(t_node));
	*tmp = (t_node){num, NULL, NULL};
	return tmp;
}

void	pushInt(t_stack *stack, int num)
{
	push(stack, newStackNode(num));
}

void	push(t_stack *stack, t_node *node)
{
	if (node)
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