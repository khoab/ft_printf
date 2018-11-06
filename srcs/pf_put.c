/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:25:53 by kbui              #+#    #+#             */
/*   Updated: 2018/10/31 23:19:33 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "helper.h"

char	*pf_putstr_until(char *str, char c, int *ret)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	write(1, str++, len);
	*ret += len;
	return (str + len);
}

char	pf_putstr
