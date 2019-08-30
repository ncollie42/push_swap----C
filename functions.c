#include "header.h"

void    rra(t_stack *A, t_stack *B)
{
    rotateDown(A);
}

void    rrb(t_stack *A, t_stack *B)
{
    rotateDown(B);
}

void    rrr(t_stack *A, t_stack *B)
{
    rotateDown(A);
    rotateDown(B);
}
