/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inline_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:29:04 by kbui              #+#    #+#             */
/*   Updated: 2018/11/07 10:44:15 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

inline int		ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

inline int		ft_toupper(int c)
{
	return ((c >= 'a' && c <= 'z') ? (c -= 32) : c);
}

inline int		ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? (c += 32) : c);
}

inline int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
