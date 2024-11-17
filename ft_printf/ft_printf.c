/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:40:57 by huozturk          #+#    #+#             */
/*   Updated: 2024/11/14 17:33:02 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdarg.h>

void ft_identifier(const char *format, va_list args, int *value)
{
	if(*format == 'd')
		*value += ft_putchar(va_arg(args, int) + '0');
	else if (*format == 'c')
		*value += ft_putchar(va_arg(args, int));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	value;
	int temp;
	va_start(args, format);
	
	value = 0;
	temp = 0;
	while (*format)
	{
		if (*format == '%')
			ft_identifier((++format), args, &value);
		else
		{
			ft_putchar(*format);
		}
		format++;
	}
	if (temp == -1)
		return (-1);
	value += temp;

	return (value);
}