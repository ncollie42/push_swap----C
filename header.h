#ifndef HEADER_H
#define HEADER_H

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

#endif