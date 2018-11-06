/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:57:16 by kbui              #+#    #+#             */
/*   Updated: 2018/11/05 13:04:44 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>

typedef struct	s_flags
{
	int			hash;
	int			zero;
	int			plus;
	int			dash;
	int			space;
}				t_flags;

typedef enum	e_modifier
{
	NONE, HH, H, LL, L, J, Z
}				t_modifier;

typedef struct	s_conversion
{
	char				*start;
	t_flags				*flags;
	int					min_width;
	int					precision;
	int					prec_set;
	t_modifier			modif;
	char				type;
	char				sign;
}				t_conversion;

/*
** Main thing to call all the other function
*/

int				ft_printf(const char *format, ...);
t_conversion	*pf_new_conversion(char *str);
char			*pf_conversion(va_list arg, char *str, int *ret);
void			pf_del_conversion(t_conversion *cvss);

/*
** Parsing functions
*/

char			*pf_parse_conversion(char *str, t_conversion *cvss);

/*
** Str case handler
*/

void			pf_wrd_case(va_list arg, t_conversion *cvss);
void			pf_putwchar(t_conversion *cvss, wint_t wint);
void			pf_putwstr(t_conversion *cvss, wchar_t *str);
void			pf_putchar(t_conversion *cvss, char c);
void			pf_putstr(t_conversion *cvss, char *str);

/*
** Num case hanlder
*/

void			pf_num_case(va_list arg, t_conversion *cvss);
void			pf_d_case(t_conversion *cvss, intmax_t inum);
void			pf_u_case(t_conversion *cvss, uintmax_t unum);
void			pf_o_case(t_conversion *cvss, uintmax_t unum);
void			pf_X_case(t_conversion *cvss, uintmax_t unum);
void			pf_xp_case(t_conversion *cvss, uintmax_t unum);

/*
** Some helper function
*/

char			*pf_putstr_until(char *str, char c, int *ret);

#endif
