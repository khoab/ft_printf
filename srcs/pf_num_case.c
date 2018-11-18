/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_num_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:56:02 by kbui              #+#    #+#             */
/*   Updated: 2018/11/17 16:53:40 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helper.h"

void		pf_put_all(t_conversion *cvss, char *num_str, int str_len)
{
	if (cvss->flags->dash)
	{
		pf_print_str(num_str);
		pf_print_space_or_0(str_len, cvss->min_width, ' ');
		return ;
	}
	if (cvss->flags->zero)
		pf_print_space_or_0(str_len, cvss->min_width, '0');
	else
		pf_print_space_or_0(str_len, cvss->min_width, ' ');
	pf_print_str(num_str);
}

static void	pf_d_case(t_conversion *cvss, char *num_str, int *i)
{
	if (cvss->flags->zero && cvss->sign)
	{
		pf_pacount(&(cvss->sign), 1);
		cvss->min_width -= 1;
	}
	else if (cvss->sign)
		num_str[--(*i)] = cvss->sign;
}

static void	pf_xpcapx_case(t_conversion *cvss, char *num_str, int *i)
{
	if (cvss->flags->zero && ((cvss->flags->hash
		&& *i < 99 && num_str[98] != '0') || cvss->type == 'p')
		&& ((cvss->type != 'X') ? pf_pacount("0x", 2) : pf_pacount("0X", 2)))
		cvss->min_width -= 2;
	else if (((cvss->flags->hash && *i < 99
		&& num_str[98] != '0') || cvss->type == 'p'))
	{
		num_str[--(*i)] = (cvss->type != 'X') ? 'x' : 'X';
		num_str[--(*i)] = 48;
	}
}

void		pf_itoa_base(t_conversion *cvss, uintmax_t num, int base)
{
	static char *def_base;
	char		num_str[100];
	int			i;

	def_base = (cvss->type != 'X') ? "0123456789abcdef" : "0123456789ABCDEF";
	i = 99;
	num_str[i] = '\0';
	if (num > 0 || !cvss->prec_set)
		num_str[--i] = def_base[num % base];
	while ((num /= base) > 0)
		num_str[--i] = def_base[num % base];
	if (cvss->type == 'o' && cvss->flags->hash && num_str[i] != def_base[0])
		num_str[--i] = 48 + (num % base);
	if (cvss->precision > 99 - i)
		cvss->flags->zero = 0;
	while (cvss->precision > 99 - i)
		num_str[--i] = def_base[0];
	if (ft_strchr("xpX", cvss->type))
		pf_xpcapx_case(cvss, num_str, &i);
	else if (cvss->type == 'd' || cvss->type == 'b')
		pf_d_case(cvss, num_str, &i);
	pf_put_all(cvss, (num_str + i), (99 - i));
}
