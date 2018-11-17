/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_case_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:31:32 by kbui              #+#    #+#             */
/*   Updated: 2018/11/16 17:42:27 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helper.h"

/*
** Reverses a string 'str' of length 'len'
*/

static void	pf_reverse(char *str, int len)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

/*
** Converts a given integer x to string.  d is the number
** of digits required in output. If d is more than the number
** of digits in x, then 0s are added at the beginning.
*/

uintmax_t	pf_f_itoa(uintmax_t x, char *str, uintmax_t d)
{
	uintmax_t	i;

	i = -1;
	str[++i] = (x % 10) + '0';
	while (x /= 10)
		str[++i] = (x % 10) + '0';
	while (++i < d)
		str[i] = '0';
	pf_reverse(str, i);
	str[i] = '\0';
	return (i);
}

/*
** Use to conver floating number to a string
*/

static char	*pf_mod_strcat(char *dst, const char *src, int *len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	*len = i;
	return (dst);
}

static void	pf_f_print(char *num_str, t_conversion *cvss)
{
	int		len;
	char	sign[2];

	len = 0;
	if (cvss->flags->zero && cvss->sign)
	{
		pf_pacount(&(cvss->sign), 1);
		cvss->min_width -= 1;
	}
	else if (cvss->sign)
	{
		sign[0] = cvss->sign;
		sign[1] = '\0';
		num_str = pf_mod_strcat(sign, num_str, &len);
	}
	pf_put_all(cvss, num_str, len);
}

void		pf_ftoa(va_list arg, t_conversion *cvss)
{
	long double			n;
	char				num_str[100];
	uintmax_t			after_dot;
	uintmax_t			i;
	long double			second_part;

	after_dot = (!cvss->prec_set) ? 6 : cvss->precision;
	ft_memset(&num_str, 0, 99);
	n = (cvss->modif == CAPL) ?
			(va_arg(arg, long double)) : (va_arg(arg, double));
	if (n < 0 && (n *= -1))
		cvss->sign = '-';
	else if (cvss->flags->plus)
		cvss->sign = '+';
	else if (cvss->flags->space)
		cvss->sign = ' ';
	second_part = n - (long double)(uintmax_t)n;
	i = pf_f_itoa((uintmax_t)n, num_str, 0);
	if (after_dot != 0)
	{
		num_str[i] = '.';
		second_part *= ft_pow(10, after_dot);
		pf_f_itoa((uintmax_t)second_part, num_str + i + 1, after_dot);
	}
	pf_f_print(num_str, cvss);
}
