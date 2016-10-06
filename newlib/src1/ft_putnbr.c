/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 21:18:46 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/22 16:37:59 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int trunc;
	int called;

	called = 0;
	trunc = 1000000000;
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb %= 1000000000;
		}
		nb *= -1;
	}
	while (trunc > 0)
	{
		if ((nb / trunc) != 0 || called == 1 || (nb == 0 && trunc == 1))
		{
			called = 1;
			ft_putchar((nb / trunc) + '0');
		}
		nb %= trunc;
		trunc /= 10;
	}
}
