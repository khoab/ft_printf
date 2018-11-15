/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 23:58:22 by kbui              #+#    #+#             */
/*   Updated: 2018/11/14 22:07:55 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlen(const char *str);
extern int	ft_isspace(int c);
extern int	ft_toupper(int c);
extern int	ft_tolower(int c);
extern int	ft_isdigit(int c);
int			ft_atoi(const char *str);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
long long	ft_pow(int x, unsigned int y);
char		*ft_strcat(char *dst, const char *src);
void		*ft_memalloc(size_t size);

#endif
