/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_case_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:31:32 by kbui              #+#    #+#             */
/*   Updated: 2018/11/15 15:43:59 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helper.h"

static char	*pf_moded_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*dot;
	size_t	len;

	dot = ".";
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	str = ft_memalloc(len);
	if (str)
	{
		str = ft_strcat(str, s1);
		str = ft_strcat(str, dot);
		str = ft_strcat(str, s2);
	}
	return (str);
}

static char	*pf_triple_strjoin(char c, const char *s1, const char *s2)
{
	char	*str;
	char	*dot;
	char	sign[2];
	size_t	len;

	dot = ".";
	sign[0] = c;
	sign[1] = '\0';
	len = ft_strlen(s1) + ft_strlen(s2) + 3;
	str = ft_memalloc(len);
	if (str)
	{
		str = ft_strcat(str, sign);
		str = ft_strcat(str, s1);
		str = ft_strcat(str, dot);
		str = ft_strcat(str, s2);
	}
	return (str);
}
#include <math.h>
static char	*pf_ftoa(int n)
{
	char				*str;
	size_t				str_len;
	int	tmp_nbr;
	
	str_len = 1;
	tmp_nbr = (int)n;
	while (tmp_nbr /= 10)
		str_len++;
	str = ft_strnew(str_len);
	str[--str_len] = n % 10 + '0';
	while (n /= 10)
		str[--str_len] = n % 10 + '0';
	printf("%s\n", str);
	return (str);
}

static void	pf_f_case_cont(char *whole_str, char *dec_precision_str,
								t_conversion *cvss)
{
	char	*full_str;

	if (cvss->flags->zero && cvss->sign)
	{
		pf_pacount(&(cvss->sign), 1);
		cvss->min_width -= 1;
	}
	else if (cvss->sign)
	{
		full_str = pf_triple_strjoin(cvss->sign, whole_str, dec_precision_str);
		pf_put_all(cvss, full_str, ft_strlen(full_str));
		ft_strdel(&whole_str);
		ft_strdel(&dec_precision_str);
		return ;
	}
	full_str = pf_moded_strjoin(whole_str, dec_precision_str);
	ft_strdel(&whole_str);
	ft_strdel(&dec_precision_str);
	pf_put_all(cvss, full_str, ft_strlen(full_str));
}

static void pf_sign(long double f, t_conversion *cvss)
{
	if (f < 0)
		cvss->sign = '-';
	else if (cvss->flags->plus)
		cvss->sign = '+';
	else if (cvss->flags->space)
		cvss->sign = ' ';
}

void		pf_f_case(va_list arg, t_conversion *cvss)
{
	long double			f;
	long double			dec_precision_num;
	char				*whole_str;
	char				*dec_precision_str;
	
	f = (cvss->modif == LL) ?
		(va_arg(arg, long double)) : (va_arg(arg, double));
	pf_sign(f, cvss);
	if (f < 0)
		f = -f;
	whole_str = pf_ftoa((int)f);
	dec_precision_num = (!cvss->prec_set) ? ((f - (int)f) * pow(10, 6))
		: ((f - (int)f) * pow(10, cvss->precision));
	printf("%0.16Lf\n", (long double)0.42);
	dec_precision_str = pf_ftoa((int)dec_precision_num);
	printf("%s\n", dec_precision_str);
	pf_f_case_cont(whole_str, dec_precision_str, cvss);
}
