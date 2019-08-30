#include "header.h"

void    ra(t_stack *A, t_stack *B)
{
    rotateUp(A);
}

void    rb(t_stack *A, t_stack *B)
{
    rotateUp(B);
}

void    rr(t_stack *A, t_stack *B)
{
    rotateUp(A);
    rotateUp(B);
}
