/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:43:12 by kbui              #+#    #+#             */
/*   Updated: 2018/11/15 13:15:58 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_mod(double a, double b)
{
	long double	mod;
	
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	mod = a;
	while (a > b)
		mod -= b;
	if (a < 0)
		return (-mod);
	return (mod);	
}