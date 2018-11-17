/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:25:53 by kbui              #+#    #+#             */
/*   Updated: 2018/11/16 17:05:36 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "helper.h"

char		*pf_putstr_until(char *str, char c)
{
	while (*str != '\0' && *str != c)
		pf_pacount(str++, 1);
	return (str);
}

void		pf_print_space_or_0(int str_len, int min, char c)
{
	while (min-- > str_len)
		pf_pacount(&c, 1);
}

int			pf_printed_count(int size, int add)
{
	static int	total = 0;
	static int	locked = 0;

	if (add == 0)
	{
		size = total;
		total = 0;
		locked = 0;
		return (size);
	}
	if (add == -1)
	{
		total = -1;
		locked = 1;
		return (total);
	}
	if (!locked)
		total += size;
	if (add == -2)
		locked = 1;
	return (total);
}

int			pf_pacount(void *mem, int size)
{
	char	*str;
	int		ret;
	int		i;

	str = mem;
	i = 0;
	while (i < size)
	{
		ret = write(1, str + i, 1);
		if (ret == -1)
			pf_printed_count(0, -1);
		else
			pf_printed_count(1, 1);
		i++;
	}
	return (1);
}

void		pf_print_str(char *str)
{
	pf_pacount(str, ft_strlen(str));
}
