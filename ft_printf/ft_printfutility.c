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

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
static int	ft_putnbrutility(long num, const char checkidentifier, const char *type)
{
	long	len;

	len = 0;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len += ft_putnbr(-num, checkidentifier, type) + 1;
	}
	else if (num > (ft_strlen(type)-1))
	{
		len += ft_putnbr(num/ft_strlen(type), checkidentifier, type);
		len += ft_putnbr(num%ft_strlen(type), checkidentifier, type);
	}
	else if (num < 10)
	{
		if (ft_putchar(num + '0') == -1)
			return (-1);
		len++;
	}
	else
		if (checkidentifier == 'x')
				len += ft_putchar((num - 10 + 'a'));
	return (len);
}

int	ft_putnbr(long num, const char checkidentifier, const char *type)
{
	long		len;

	len = 0;
	len = ft_putnbrutility(num, checkidentifier, type);
	return ((int)len);
}
