#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(char *str)
{
	int len;

	len = 0;
	if (!str)
    {
        ft_putstr("(null)");
        return (6);
    }
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

static int	ft_strlen(const char *str)
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

static int ft_putalnum(char checkidentifier, unsigned long hexnum, long decnum)
{
	if (checkidentifier == 'p')
	{
		if (ft_putchar(hexnum + '0') == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(decnum + '0') == -1)
			return (-1);
	}
	return (0);
}
static int ft_puthexdigit(char checkidentifier, unsigned long hexnum, long decnum)
{
	if (checkidentifier == 'x' || checkidentifier == 'X' || checkidentifier == 'p')
	{
		if (checkidentifier == 'X')
		{
			if (ft_putchar(decnum - 10 + 'A') == -1)
				return (-1);
		}
		else if (checkidentifier == 'p')
		{
			if (ft_putchar(hexnum - 10 + 'a') == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(decnum - 10 + 'a') == -1)
				return (-1);
		}
	}
	else
		if (ft_putchar(decnum - 10 + 'a') == -1)
			return (-1);
	return (0);
}
// int	ft_putnbrutility(unsigned long num, const char checkidentifier, const char *type)
// {
// 	long	len;

// 	len = 0;
// 	if (num > (unsigned long)(ft_strlen(type)-1) && checkidentifier == 'p')
// 	{
// 		len += ft_putnbrutility(num/ft_strlen(type), checkidentifier, type);
// 		len += ft_putnbrutility(num%ft_strlen(type), checkidentifier, type);
// 	}
// 	else if (num < 10 && checkidentifier == 'p')
// 	{
// 		if (ft_putchar(num + '0') == -1)
// 			return (-1);
// 		len++;
// 	}
// 	else
// 	{
// 		if (ft_putchar((num - 10 + ((checkidentifier == 'x' || checkidentifier == 'p') ? 'a' : 'A'))) == -1)
// 			return (-1);
// 		len++;
// 	}
// 	return ((int)len);
// }				//	NULL İŞLEMİ YAPILACAK

int	ft_putnbr(long decnum, unsigned long hexnum,const char checkidentifier, const char *type)
{
	long		len;

	len = 0;
	if (decnum < 0 || hexnum < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len += ft_putnbr(-decnum, -hexnum, checkidentifier, type) + 1;
	}
	else if (decnum > (ft_strlen(type)-1) || hexnum > (ft_strlen(type) - 1))
	{
		len += ft_putnbr(decnum/ft_strlen(type), hexnum/ft_strlen(type),checkidentifier, type);
		len += ft_putnbr(decnum%ft_strlen(type), hexnum%ft_strlen(type),checkidentifier, type);
	}
	else if ((decnum < 10 && hexnum == 0) || (hexnum < 10 && decnum == 0))
	{
		if (ft_putalnum(checkidentifier, hexnum, decnum) == -1)
			return (-1);
		len++;
	}
	else
		if (++len && ft_puthexdigit(checkidentifier, hexnum, decnum) == -1)
			return (-1);
	return ((int)len);
}
