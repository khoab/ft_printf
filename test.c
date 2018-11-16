/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:37:14 by kbui              #+#    #+#             */
/*   Updated: 2018/11/15 13:39:03 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

inline static void	show_me_the_magic(unsigned long long num)
{
	printf("%llu\n", num);
}
int		main(void)
{
	long double f;

	f = 420000.000000;
	show_me_the_magic(f);
	printf("%llu\n", (unsigned long long)f);
}