#include "libftprintf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
int	ft_putstr(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		if (ft_putchar(*str) == -1)
			return (-1);
		else
			len++;
		str++;
	}
	return (len);
}

int	ft_putnbr(long num)
{
	long		len;

	len = 0;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		len += ft_putnbr(-num);
	}
	else if (num > 9)
	{
		len += ft_putnbr(num/10);
		len += ft_putnbr(num%10);
	}
	else
	{
		if (ft_putchar(num + '0') == -1)
			return (-1);
		len++;
	}
	return ((int)len);
}
