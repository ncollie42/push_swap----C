#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

#define CHECKZERO(x) ((x)[0] != '0')

void    error(void)
{
    printf("Error\n");
    exit(EXIT_FAILURE);
}
typedef enum command{SA, SB, SS, PA, PB, RA ,RB, RR, RRA, RRB, RRR, ERROR}command;

command getCommand(char *str)
{
    if ((strcmp(str, "sa") == 0))
        return SA;
    else if ((strcmp(str, "sb") == 0))
        return SB;
    else if ((strcmp(str, "ss") == 0))
        return SS;
    else if ((strcmp(str, "pa") == 0))
        return PA;
    else if ((strcmp(str, "pb") == 0))
        return PB;
    else if ((strcmp(str, "ra") == 0))
        return RA;
    else if ((strcmp(str, "rb") == 0))
        return RB;
    else if ((strcmp(str, "rr") == 0))
        return RR;
    else if ((strcmp(str, "rra") == 0))
        return RRA;
    else if ((strcmp(str, "rrb") == 0))
        return RRB;
    else if ((strcmp(str, "rrr") == 0))
        return RRR;
     return ERROR;
}

void scanner(void)
{
    char buff[4];
    int num;
    // t_list **operation;
    command tmp;
    // operation = init
    while ((num = read(0, buff, 4)) > 0)
    {
        buff[num - 1] = '\0';
        tmp = getCommand(buff); //buffer leaks into stdout when error
        if (tmp == ERROR)
            error();
        // append(operation, newNode(tmp));
    }
    // return operation
}

int main(int argc, char **argv)
{
    int num;

    while(argc-- > 1)
    {
        num = atoi(*(++argv));
        if(!num && CHECKZERO(*argv))
            error();
        else
        printf("%d\n", num); // Add num to stackAf
    }
    scanner();

    // returns a list of indexs, then make a talbe with function pointers and use those
    //

}