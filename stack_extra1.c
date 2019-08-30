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

// void	print(t_stack *stack)
// {
// 	t_node *tmp = stack->top;

// 	while(tmp)
// 	{
// 		printf("%d", tmp->num);
// 		if (tmp->below)
// 			printf(" - ");
// 		tmp = tmp->below;
// 	}
// 	printf(" || Bot");
// }

void	rotateUp(t_stack *stack)
{
	t_node *tmp;

	if (stack->top && stack->top->below)
	{
		tmp = stack->top;
		stack->top = stack->top->below;
		tmp->above = stack->bot;
		tmp->below = NULL;
		stack->bot->below = tmp;
		stack->bot = tmp;
	}
}

void	rotateDown(t_stack *stack)
{
	t_node *tmp;

	if (stack->top && stack->top->below)
	{
		tmp = stack->bot;
		stack->bot = stack->bot->above;
		stack->bot->below = NULL;
		stack->top->above = tmp;
		tmp->below = stack->top;
		stack->top = tmp;
		stack->top->above = NULL;
	}
}
