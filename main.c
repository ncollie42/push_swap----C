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
typedef enum command{SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR, ERROR}command;

func table[] = {sa, sb, ss};

// functionpointers()
func getCommand(char *str)
{
    if ((strcmp(str, "sa") == 0))
        return ss;
    else if ((strcmp(str, "sb") == 0))
        return sb;
    else if ((strcmp(str, "ss") == 0))
        return ss;
    return NULL;
}
    // else if ((strcmp(str, "pa") == 0))
    //     return PA;
    // else if ((strcmp(str, "pb") == 0))
    //     return PB;
    // else if ((strcmp(str, "ra") == 0))
    //     return RA;
    // else if ((strcmp(str, "rb") == 0))
    //     return RB;
    // else if ((strcmp(str, "rr") == 0))
    //     return RR;
    // else if ((strcmp(str, "rra") == 0))
    //     return RRA;
    // else if ((strcmp(str, "rrb") == 0))
    //     return RRB;
    // else if ((strcmp(str, "rrr") == 0))
    //     return RRR;
    //  return ERROR;
// }

void scanner(void)
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
    // return operation
}

int main(int argc, char **argv)
{
    int num;

    t_stack *A;

    A = malloc(sizeof(t_stack)); // init func?
    while(argc-- > 1)
    {
        num = atoi(*(++argv));
        if(!num && !strcmp(*argv, "0"))
            error();
        else
            pushInt(A, num);
            // printf("%d\n", num); // Add num to stackAf
    }
    print(A);
    // scanner();

    // returns a list of indexs, then make a talbe with function pointers and use those
    //

}