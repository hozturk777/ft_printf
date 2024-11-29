/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:38:40 by huozturk          #+#    #+#             */
/*   Updated: 2024/11/28 15:23:56 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int main()
{
    int c = 0;
    printf(" - len1: %d\n",ft_printf("% x", 123));
    printf(" - len2: %d\n",printf("% x", 123));
}