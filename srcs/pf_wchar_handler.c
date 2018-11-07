/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wchar_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:16:53 by kbui              #+#    #+#             */
/*   Updated: 2018/11/07 11:26:52 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "helper.h"

static size_t	pf_wstrlen(wchar_t *wstr)
{
	wchar_t *tmp;

	tmp = wstr;
	while (*tmp != L'\0')
		tmp++;
	return (tmp - wstr);
}

static int		wchr_count(t_conversion *cvss, wchar_t *wstr, int *size)
{
	int		i;
	int		add;
	int		total;

	i = 0;
	add = 0;
	total = 0;
	while (i < *size)
	{
		if (wstr[i] <= 0x7F)
			add = 1;
		else if (wstr[i] <= 0x7FF)
			add = 2;
		else if (wstr[i] <= 0xFFFF)
			add = 3;
		else if (wstr[i] <= 0x10FFFF)
			add = 4;
		if (cvss->prec_set && cvss->type == 's'
			&& (total + add) > cvss->precision)
			break ;
		total += add;
		i++;
	}
	*size = i;
	return (total);
}

static void		pf_putwchars(t_conversion *cvss, wchar_t *wstr, int size)
{
	int	i;
	int total;

	total = wchr_count(cvss, wstr, &size);
	if (!(cvss->flags->dash))
		(cvss->flags->zero) ? pf_print_space_or_0(total, cvss->min_width, 48)
		: pf_print_space_or_0(total, cvss->min_width, 32);
	i = -1;
	while (++i < size)
		pf_putwint(wstr[i]);
	if (cvss->flags->dash)
		pf_print_space_or_0(total, cvss->min_width, 32);
}

void			pf_putwchar(t_conversion *cvss, wint_t wint)
{
	wchar_t	wchar;

	if (wint > 0x10FFFF)
		exit(1);
	wchar = (wchar_t)wint;
	pf_putwchars(cvss, &wchar, 1);
}

void			pf_putwstr(t_conversion *cvss, wchar_t *wstr)
{
	if (!wstr)
		pf_putstr(cvss, NULL);
	else
		pf_putwchars(cvss, wstr, pf_wstrlen(wstr));
}
