/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:38:40 by huozturk          #+#    #+#             */
/*   Updated: 2024/11/27 14:49:32 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int main()
{
    int c = 0;
    // printf(" - len1: %d\n",ft_printf("%         d", 123));
    printf(" - len2: %d\n",printf("%c", 200));
}