/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wrd_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:20:18 by kbui              #+#    #+#             */
/*   Updated: 2018/11/07 11:22:40 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helper.h"

static void			pf_putchars(t_conversion *cvss, char *str, int size)
{
	if (cvss->prec_set && cvss->type == 's')
		size = (size < cvss->precision ? size : cvss->precision);
	if (cvss->flags->dash)
	{
		pf_pacount(str, size);
		pf_print_space_or_0(size, cvss->min_width, ' ');
		return ;
	}
	if (cvss->flags->zero)
		pf_print_space_or_0(size, cvss->min_width, 48);
	else
		pf_print_space_or_0(size, cvss->min_width, ' ');
	pf_pacount(str, size);
}

inline void	pf_putchar(t_conversion *cvss, char c)
{
	pf_putchars(cvss, &c, 1);
}

void				pf_putstr(t_conversion *cvss, char *str)
{
	if (!str)
		str = "(null)";
	pf_putchars(cvss, str, ft_strlen(str));
}

/*
** This function use for string case only
*/

void				pf_wrd_case(va_list arg, t_conversion *cvss)
{
	if (ft_strchr("CS", cvss->type))
	{
		cvss->modif = L;
		cvss->type = ft_tolower(cvss->type);
	}
	if (cvss->modif == L)
	{
		if (cvss->type == 'c')
			pf_putwchar(cvss, va_arg(arg, wint_t));
		else if (cvss->type == 's')
			pf_putwstr(cvss, va_arg(arg, wchar_t*));
		else
			pf_putchar(cvss, cvss->type);
	}
	else
	{
		if (cvss->type == 'c')
			pf_putchar(cvss, va_arg(arg, int));
		else if (cvss->type == 's')
			pf_putstr(cvss, va_arg(arg, char*));
		else
			pf_putchar(cvss, cvss->type);
	}
}

/*
** This function use to print set string then print out wchar_t
*/

void				pf_putwint(wint_t wint)
{
	char	str[4];

	if (wint <= 0x7F)
		pf_pacount(&wint, 1);
	else if (wint <= 0x7FF)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
		pf_pacount(str, 2);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
		pf_pacount(str, 3);
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wint & 0x003F) + 0x80);
		pf_pacount(str, 4);
	}
}
