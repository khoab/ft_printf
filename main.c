/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:45:54 by kbui              #+#    #+#             */
/*   Updated: 2018/11/15 14:03:06 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int		main(void)
{
	long double f = 420000.000000;
	int	 i = -2412412;
	int len = printf("First, I tried to print this fking number 1.42 by reg_printf %f\n", 1.42);
	int len2 = ft_printf("This is the result of my fking ft_printf: \n%f\n", 1.42);
	// printf("%d === %d\n", len, len2);
	return (0);
}