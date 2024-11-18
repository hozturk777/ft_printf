/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsyn <hsyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:38:22 by huozturk          #+#    #+#             */
/*   Updated: 2024/11/18 18:56:42 by hsyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int ft_printf(const char *, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int ft_putnbr(long  num);

#endif