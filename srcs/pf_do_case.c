/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_do_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:56:02 by kbui              #+#    #+#             */
/*   Updated: 2018/11/05 18:07:50 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helper.h"

inline void	pf_print_space_or_0(int str_len, int min, char c)
{
	int		i;

	i = min - str_len;
	if (i > 0)
		pf_pacount(&c, i);
}

void		pf_put_all(t_conversion *cvss, char *num_str, int str_len)
{
	if (cvss->flags->dash)
	{
		pf_print_str(num_str);
		pf_print_space_or_0(str_len, cvss->min_width, ' ');
		return ;
	}
	else if (cvss->flags->zero)
		pf_print_space_or_0(str_len, cvss->min_width, '0');
	else if (cvss->flags->space)
		pf_print_space_or_0(str_len, cvss->min_width, ' ');
	pf_print_str(num_str);
}

void		pf_d_case(t_conversion *cvss, intmax_t num)
{
	char	num_str[100];
	int		i;

	i = 99;
	num_str[i] = '\0';
	if (num == 0)
		num_str[--i] = 48;
	else
		num_str[--i] = (num > 0) ? 48 + (num % 10) : 48 - (num % 10);
	while ((num /= 10) > 0)
		num_str[--i] = (num > 0) ? 48 + (num % 10) : 48 - (num % 10);
	if (cvss->precision > 99 - i)
		cvss->flags->zero = 0;
	while (cvss->precision > 99 - i)
		num_str[--i] = 48;
	if (cvss->flags->zero && cvss->sign)
	{
		pf_pacount(&(cvss->sign), 1);
		cvss->min_width -= 1;
	}
	else
		num_str[--i] = cvss->sign;
	pf_put_all(cvss, (num_str + i), (99 - i));
}

void		pf_itoa_base(t_conversion *cvss, uintmax_t num, uintmax_t base)
{
	static char *def_base;
	char		num_str[100];
	int			i;

	def_base = (cvss->type != 'X') ? "0123456789abcdef" : "0123456789ABCDEF";
	i = 99;
	num_str[i] = '\0';
	num_str[--i] = (num == 0) ? def_base[0] : def_base[num % base];
	while ((num /= 10) > 0)
		num_str[--i] = def_base[num % base];
	if (cvss->type == 'o' && cvss->flags->hash && num_str[i] != def_base[0])
		num_str[--i] = 48 + (num % base);
	while (cvss->precision > 99 - i && (cvss->flags->zero = 0))
		num_str[--i] = def_base[0];
	if (cvss->flags->zero && ((cvss->flags->hash
		&& i < 99 && num_str[98] != '0') || cvss->type == 'p')
		&& ((cvss->type != 'X') ? pf_pacount("0x", 2) : pf_pacount("0X", 2)))
		cvss->min_width -= 2;
	else if ((cvss->flags->hash && i < 99 && num_str[98] != '0')
		|| cvss->type == 'p')
	{
		num_str[--i] = (cvss->type != 'X') ? 'x' : 'X';
		num_str[--i] = def_base[0];
	}
	pf_put_all(cvss, (num_str + i), (99 - i));
}
