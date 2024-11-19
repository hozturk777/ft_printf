/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:40:57 by huozturk          #+#    #+#             */
/*   Updated: 2024/11/19 16:11:20 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdarg.h>

int is_valid_format(char c)
{
    return (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

void ft_identifier(const char *format, va_list args, int *temp)
{
	 if (*format == '%')
        *temp += ft_putchar('%');
    else if ((*format == 'd' || *format == 'i'))
        *temp += ft_putnbr(va_arg(args, int));
    else if (*format == 'c')
        *temp += ft_putchar(va_arg(args, int));
    else if (*format == 's')
        *temp += ft_putstr(va_arg(args, char *));
}




int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	value;
	int temp;
	va_start(args, format);
	
	value = 0;
	while (*format)
	{
		temp = 0;
		if (*format == '%')
		{
			format++;
            while (*format == ' ')
            {
                if(is_valid_format(*(format+1)))
					temp += ft_putchar(' ');
                format++;
            }
            ft_identifier(format, args, &temp);
		}
		else
		{
			temp += ft_putchar(*format);
		}
		format++;
		if (temp == -1)
			return (-1);
		value += temp;
	}

	return (value);
}