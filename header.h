#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>

typedef struct      s_node
{
    int             num;
    struct s_node *above;
    struct s_node *below;
}   t_node;

typedef struct      s_stack
{
    t_node *top;
    t_node *bot;
}   t_stack;

/* stack functions */

void	swapTop(t_stack *stack);
void	push(t_stack *stack, t_node *node);

/* stack functions x2 */

void    sa(t_stack *A, t_stack *B);
void    sb(t_stack *A, t_stack *B);
void    ss(t_stack *A, t_stack *B);

/* Testing */

void	print(t_stack *stack);
void	pushInt(t_stack *stack, int num);
#endif