#include "header.h"

void    sa(t_stack *A, t_stack *B)
{
    swapTop(A); //void out B so it doesn't complain
}
void    sb(t_stack *A, t_stack *B)
{
    swapTop(B);
}
void    ss(t_stack *A, t_stack *B)
{
    swapTop(A);
    swapTop(B);
}