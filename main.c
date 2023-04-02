# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int	        sign;

	result = 0;
	sign = 1;
	while ((8 < *str && *str < 14) || (*str == 32))
		str++;
	if (45 == *str || 43 == *str)
	{
		if (*str == 45)
			sign = sign * -1;
		str++;
	}
	while (47 < *str && *str < 58)
	{
		result = (result * 10) + *str - '0';
		str++;
	}
    if (result <= 0 || result > 2147483647)
        return (-1);
	return (result * sign);
}

int ft_error()
{
    write(1,"error\n"6);
    exit()
}

int main(int argc, char **argv)
{
    if ()
}