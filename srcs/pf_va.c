/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_va.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:05:46 by kbui              #+#    #+#             */
/*   Updated: 2018/11/05 17:26:14 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helper.h"

t_conversion	*pf_new_conversion(char *str)
{
	t_conversion	*cvss;
	t_flags			*flags;

	ft_memset(&cvss, 0, sizeof(cvss));
	ft_memset(&flags, 0, sizeof(flags));
	cvss->start = str;
	cvss->flags = flags;
	cvss->modif = NONE;
	return (cvss);
}

char			*pf_conversion(va_list arg, char *str, int *ret)
{
	t_conversion	*cvss;
	int				printed;

	cvss = pf_new_conversion(str);
	str = pf_parse_conversion(str, cvss);
	if (ft_strchr(("idDoOuUxXp"), cvss->type))
		pf_num_case(arg, cvss);
	else
		pf_wrd_case(arg, cvss);
	pf_del_conversion(cvss);
	*ret = printed;
	return (str);
}

int				ft_printf(const char *format, ...)
{
	char			*str;
	va_list			arg;
	int				ret;

	va_start(arg, format);
	str = (char *)format;
	ret = 0;
	while (*str != '\0')
	{
		str = pf_putstr_until(str, '%', &ret);
		if (!*str)
			break ;
		str++;
		str = pf_conversion(arg, str, &ret);
	}
	va_end(arg);
	return (ret);
}
