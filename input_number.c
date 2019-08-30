#include "nc_lib.h"
#include "header.h"
#include <limits.h>
#include <stdbool.h>

static int	skip_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int			special_atoi(const char *str)
{
	int				sign;
	unsigned int	index;
	long	num;

	num = 0;
	index = 0;
	sign = 1;
	while (skip_space(str[index]))
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (nc_isdigit(str[index]))
	{
		num = num * 10 + str[index] - '0';
		index++;
		if (num > INT_MAX || num < INT_MIN)
			error();
	}
	return (num * sign);
}

bool    isDup(int num)
{
    static int table[42949672945];

    if (table[(unsigned int)num])
        return true;
    table[(unsigned int)num] = 1;
    return false;
}

void splitArg(t_stack *A, char *str)
{
    char    **tmp;
    int     n;
    int     num; 

    n = -1;
    tmp = nc_strsplit(str, ' ');
    if (tmp)
    {
        while (tmp[++n])
        {
            num = special_atoi(tmp[n]);
            if(!num && strcmp(tmp[n], "0"))
                error();
            if (isDup(num))
                error();
            pushInt(A, num);
            free(tmp[n]);
        }
        free(tmp);
    }
}

void    initStackFromArgs(t_stack *A, int argc, char **argv)
{
    int n;

    n = 0;
    while(n++ < argc)
    {
        splitArg(A, argv[n]);    //For when using Env $NUM
    }
}