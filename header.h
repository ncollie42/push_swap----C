#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
t_node	*pop(t_stack *stack);
void	rotateUp(t_stack *stack);
void	rotateDown(t_stack *stack);
bool	isSorted(t_stack *stack);
t_stack *newStack();

/* stack functions x2 */

void    sa(t_stack *A, t_stack *B);
void    sb(t_stack *A, t_stack *B);
void    ss(t_stack *A, t_stack *B);
void    pa(t_stack *A, t_stack *B);
void    pb(t_stack *A, t_stack *B);
void    ra(t_stack *A, t_stack *B);
void    rb(t_stack *A, t_stack *B);
void    rr(t_stack *A, t_stack *B);
void    rra(t_stack *A, t_stack *B);
void    rrb(t_stack *A, t_stack *B);
void    rrr(t_stack *A, t_stack *B);

/* Error */

void    error(void);

/* input number */

void    initStackFromArgs(t_stack *A, int argc, char **argv);

/* Testing */
void    verify(t_stack *A, t_stack *B);
int			special_atoi(const char *str);
void	print(t_stack *stack);
void	pushInt(t_stack *stack, int num);
#endif