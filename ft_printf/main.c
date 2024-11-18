/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huozturk <huozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:38:40 by huozturk          #+#    #+#             */
/*   Updated: 2024/11/14 17:32:21 by huozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

int main()
{
    printf("len1: %d\n",ft_printf("%d\n", 2221));
    // printf("\nlen2: %d\n",printf("%d", 3213221));
}