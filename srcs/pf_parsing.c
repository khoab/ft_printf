/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:12:06 by kbui              #+#    #+#             */
/*   Updated: 2018/11/09 01:58:21 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "helper.h"

static char	*pf_parse_flags(char *str, t_conversion *cvss)
{
	while (ft_strchr("#0-+ ", *str))
	{
		if (*str == '#')
			cvss->flags->hash = 1;
		else if (*str == '0')
			cvss->flags->zero = 1;
		else if (*str == '+')
			cvss->flags->plus = 1;
		else if (*str == '-')
			cvss->flags->dash = 1;
		else if (*str == ' ')
			cvss->flags->space = 1;
		else
			exit(1);
		str++;
	}
	if (!*str)
		exit(1);
	return (str);
}

static char	*pf_parse_width(char *str, t_conversion *cvss)
{
	cvss->min_width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (!*str)
		exit(1);
	return (str);
}

static char	*pf_parse_percision(char *str, t_conversion *cvss)
{
	if (*str != '.')
		return (str);
	str++;
	cvss->precision = ft_atoi(str);
	cvss->prec_set = 1;
	while (ft_isdigit(*str))
		str++;
	if (!*str)
		exit(1);
	return (str);
}

static char	*pf_parse_modifier(char *str, t_conversion *cvss, int check)
{
	if (!(ft_strchr("hljz", *str)))
		return (str);
	if (check == 1)
		return (str + 1);
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		cvss->modif = HH;
		return (str + 2);
	}
	if (ft_strncmp(str, "ll", 2) == 0)
	{
		cvss->modif = LL;
		return (str + 2);
	}
	if (*str == 'h')
		cvss->modif = H;
	else if (*str == 'l')
		cvss->modif = L;
	else if (*str == 'j')
		cvss->modif = J;
	else
		cvss->modif = Z;
	if (!*str)
		exit (1);
	return (str + 1);
}

char		*pf_parse_conversion(char *str, t_conversion *cvss)
{
	int		check;

	check = 0;
	while (ft_strchr("#0-+ .hljz", *str) || ft_atoi(str))
	{
		if (ft_strchr("#0-+ ", *str))
			str = pf_parse_flags(str, cvss);
		if (ft_atoi(str))
			str = pf_parse_width(str, cvss);
		if (*str == '.')
			str = pf_parse_percision(str, cvss);
		if (ft_strchr("hljz", *str))
		{
			str = pf_parse_modifier(str, cvss, check);
			check = 1;
		}
	}
	if (!*str)
		exit(1);
	cvss->type = *str;
	return (str + 1);
}

