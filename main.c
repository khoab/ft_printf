/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:06:51 by kbui              #+#    #+#             */
/*   Updated: 2018/11/09 01:27:58 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/helper.h"

char	*pf_itoa_basex(unsigned long num, int base)
{
	static char	*def_base;
	static char	buffer[50];
	char		*ptr;

	def_base = "0123456789abcdef";
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = def_base[0];
	printf("\t%lu\n", num);
	while (num != 0)
	{
		*--ptr = def_base[num % base];
		num /= base;
		printf("\t%lu\n", num);
	}
	return (ptr);
}

int		main(void)
{
	int i = printf("%hhld", 128);
	int j = ft_printf("%hhld", 128);
	printf("%d === %d\n", i, j);
	printf("Fking run\n");
	return (0);
}