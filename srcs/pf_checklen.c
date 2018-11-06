/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_checklen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:33:40 by kbui              #+#    #+#             */
/*   Updated: 2018/11/05 13:34:45 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

char	*pf_itoa_base(unsigned int num, int base)
{
	static char	*def_base;
	static char	buffer[50];
	char		*ptr;

	def_base = "0123456789abcdef";
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = def_base[0];
	while (num != 0)
	{
		*--ptr = def_base[num % base];
		num /= base;
	}
	return (ptr);
}
