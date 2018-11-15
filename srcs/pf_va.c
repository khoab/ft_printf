/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_va.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:05:46 by kbui              #+#    #+#             */
/*   Updated: 2018/11/14 19:34:52 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helper.h"

t_conversion		*pf_new_conversion(char *str)
{
	t_conversion	*cvss;
	t_flags			*flags;

	cvss = malloc(sizeof(*cvss));
	ft_memset((void *)cvss, 0, sizeof(*cvss));
	cvss->flags = malloc(sizeof(*flags));
	ft_memset((void *)cvss->flags, 0, sizeof(*flags));
	cvss->start = str;
	cvss->modif = NONE;
	return (cvss);
}

char				*pf_conversion(va_list arg, char *str)
{
	t_conversion	*cvss;

	cvss = pf_new_conversion(str);
	str = pf_parse_conversion(str, cvss);
	if (ft_strchr(("idDoOuUxXp"), cvss->type))
		pf_num_case(arg, cvss);
	else if (cvss->type == 'f')
		pf_f_case(arg, cvss);
	else
		pf_wrd_case(arg, cvss);
	free(cvss->flags);
	free(cvss);
	return (str);
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*str;

	va_start(ap, format);
	str = (char *)format;
	while (*str != '\0')
	{
		str = pf_putstr_until(str, '%');
		if (*str == '%')
			str++;
		if (*str != '\0')
			str = pf_conversion(ap, str);
	}
	va_end(ap);
	return (pf_printed_count(0, 0));
}
