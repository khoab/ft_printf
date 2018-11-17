/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:57:16 by kbui              #+#    #+#             */
/*   Updated: 2018/11/16 23:47:06 by kbui             ###   ########.fr       */
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
	NONE, HH, H, LL, L, J, Z, CAPL
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
char			*pf_conversion(va_list arg, char *str);

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
extern void		pf_putchar(t_conversion *cvss, char c);
void			pf_putstr(t_conversion *cvss, char *str);
void			pf_putwint(wint_t wint);

/*
** Num case hanlder
*/

void			pf_num_case(va_list arg, t_conversion *cvss);
void			pf_itoa_base(t_conversion *cvss, uintmax_t num, int base);
void			pf_ftoa(va_list arg, t_conversion *cvss);
void			pf_put_all(t_conversion *cvss, char *num_str, int str_len);

/*
** Putting function
*/

char			*pf_putstr_until(char *str, char c);
void			pf_print_space_or_0(int str_len, int min, char c);
int				pf_printed_count(int size, int add);
int				pf_pacount(void *mem, int size);
void			pf_print_str(char *str);

#endif
