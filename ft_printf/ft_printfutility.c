#include "libftprintf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_putstr(char c, int size)
{
	int len;

	while (size > 0)
	{
		len = ft_putchar(c);
		size--;
	}
	return (len);
}