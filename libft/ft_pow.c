/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:13:57 by kbui              #+#    #+#             */
/*   Updated: 2018/11/14 20:24:12 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_pow(int x, unsigned int y)
{
	long long temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}
