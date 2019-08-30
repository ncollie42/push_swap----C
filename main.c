#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "nc_lib.h"

void    error(void)
{
    printf("Error\n");
    exit(EXIT_FAILURE);
}
typedef void (*func)(t_stack *, t_stack *);

func getCommand(char *str)
{
    if ((strcmp(str, "sa") == 0))
        return ss;
    else if ((strcmp(str, "sb") == 0))
        return sb;
    else if ((strcmp(str, "ss") == 0))
        return ss;
    else if ((strcmp(str, "pa") == 0))
        return pa;
    else if ((strcmp(str, "pb") == 0))
        return pb;
    else if ((strcmp(str, "ra") == 0))
        return ra;
    else if ((strcmp(str, "rb") == 0))
        return rb;
    else if ((strcmp(str, "rr") == 0))
        return rr;
    else if ((strcmp(str, "rra") == 0))
        return rra;
    else if ((strcmp(str, "rrb") == 0))
        return rrb;
    else if ((strcmp(str, "rrr") == 0))
        return rrr;
    return NULL;
}

t_list  **scanner(void)
{
    char    buff[4];
    int     num;
    t_list  **operation;
    func tmp;

    operation = makeListHead();
    while ((num = read(0, buff, 4)) > 0)
    {
        buff[num - 1] = '\0';
        tmp = getCommand(buff); //buffer leaks into stdout when error
        if (!tmp)
            error();
        append(operation, newNode(tmp));
    }
    return operation;
}

void    executeComands(t_list **head, t_stack *A, t_stack *B)
{
    t_list *tmp;

    tmp = *head;
    while(tmp)
    {
        ((func)(tmp->content))(A, B);
        tmp = tmp->next;
    }
}

int main(int argc, char **argv)
{
    t_stack *A;
    t_stack *B;
    t_list **commands;

    A = newStack();
    B = newStack();
    initStackFromArgs(A, argc, argv);
    commands = scanner();
    executeComands(commands, A, B);
    verify(A, B);
}