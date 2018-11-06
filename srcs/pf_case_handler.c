/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_case_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:40:03 by kbui              #+#    #+#             */
/*   Updated: 2018/11/05 17:24:14 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helper.h"

/*
** This function because I assumed that:
** i is an alias for d
** p is just an alias to print out something similar with %hlx
** "DOU" is "dou" with l conversion
*/

inline void		is_alias(t_conversion *cvss)
{
	if (ft_strchr("DOU", cvss->type))
	{
		cvss->modif = L;
		cvss->type = ft_tolower(cvss->type);
	}
	else if (cvss->type == 'i')
		cvss->type = 'd';
	else if (cvss->type == 'p')
	{
		cvss->modif = L;
		cvss->flags->hash = 1;
	}
}

/*
** Those function to get the value of user input by signed or unsigned
*/

intmax_t		get_conv_int(va_list arg, t_conversion *cvss)
{
	if (cvss->modif == H)
		return ((short)va_arg(arg, int));
	if (cvss->modif == HH)
		return ((char)va_arg(arg, int));
	if (cvss->modif == L)
		return (va_arg(arg, long));
	if (cvss->modif == LL)
		return (va_arg(arg, long long));
	if (cvss->modif == J)
		return (va_arg(arg, intmax_t));
	return (va_arg(arg, int));
}

uintmax_t		get_conv_uint(va_list arg, t_conversion *cvss)
{
	if (cvss->modif == H)
		return ((unsigned short)va_arg(arg, unsigned int));
	if (cvss->modif == HH)
		return ((unsigned char)va_arg(arg, unsigned int));
	if (cvss->modif == L)
		return (va_arg(arg, unsigned long));
	if (cvss->modif == LL)
		return (va_arg(arg, unsigned long long));
	if (cvss->modif == J)
		return (va_arg(arg, uintmax_t));
	return (va_arg(arg, size_t));
}

/*
** This function to check case then put case in order
*/

void			pf_num_case(va_list arg, t_conversion *cvss)
{
	intmax_t	inum;
	uintmax_t	unum;

	is_alias(cvss);
	if (cvss->type == 'd')
	{
		inum = get_conv_int(arg, cvss);
		if (inum < 0 && (inum *= -1))
			cvss->sign = '-';
		else if (cvss->flags->plus)
			cvss->sign = '+';
		else if (cvss->flags->space)
			cvss->sign = ' ';
		pf_d_case(cvss, inum);
	}
	else
	{
		unum = get_conv_uint(arg, cvss);
		if (cvss->type == 'u')
			pf_itoa_base(cvss, unum, 10);
		else if (cvss->type == 'o')
			pf_itoa_base(cvss, unum, 8);
		else if (ft_strchr("xpX", cvss->type))
			pf_itoa_base(cvss, unum, 16);
	}
}

/*
** This function use for string case only
*/

void			pf_wrd_case(va_list arg, t_conversion *cvss)
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
