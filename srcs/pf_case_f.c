/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_case_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:31:32 by kbui              #+#    #+#             */
/*   Updated: 2018/11/14 22:07:51 by kbui             ###   ########.fr       */
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
	char	sign[1];
	size_t	len;

	dot = ".";
	sign[0] = c;
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
static void	pf_sign(float f, t_conversion *cvss)
{
	if (f < 0)
		cvss->sign = '-';
	else if (cvss->flags->plus)
		cvss->sign = '+';
	else if (cvss->flags->space)
		cvss->sign = ' ';
}

static size_t	get_num_len(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static char	*pf_itoa(unsigned long long n)
{
	char			*str;
	char			*tmp;
	size_t			str_len;

	str_len = get_num_len(n);
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = n % 10 + '0';
	while (n /= 10)
		str[--str_len] = n % 10 + '0';
	tmp = str;
	free(str);
	str = NULL;
	return (tmp);
}

#include <stdio.h>
#include <stdlib.h>
void		pf_f_case(va_list arg, t_conversion *cvss)
{
	long double			f;
	unsigned long long	dec_precision_num;
	char				*whole_str;
	char				*dec_precision_str;
	char				*full_str;
	char				*tmp;
	
	f = (cvss->modif == LL) ?
		(va_arg(arg, long double)) : (va_arg(arg, double));
	pf_sign(f, cvss);
	if (cvss->sign == '-')
		f *= -1;
	whole_str = pf_itoa((int)f);
	tmp = whole_str;
	printf("%s\n", whole_str);
	dec_precision_num = (!cvss->prec_set) ? ((f - (int)f) * ft_pow(10, 6))
		: ((f - (int)f) * ft_pow(10, cvss->precision));
	dec_precision_str = pf_itoa(dec_precision_num);
	printf("%s\n", whole_str);
	if (cvss->flags->zero && cvss->sign)
	{
		pf_pacount(&(cvss->sign), 1);
		cvss->min_width -= 1;
	}
	else if (cvss->sign)
	{
		full_str = pf_triple_strjoin(cvss->sign, whole_str, dec_precision_str);
		pf_put_all(cvss, full_str, ft_strlen(full_str));
		return ;
	}
	full_str = pf_moded_strjoin(whole_str, dec_precision_str);
	pf_put_all(cvss, full_str, ft_strlen(full_str));
}