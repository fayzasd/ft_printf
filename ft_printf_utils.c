/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:14:50 by fasad             #+#    #+#             */
/*   Updated: 2021/11/07 19:00:38 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	}
}

void	ft_putnbr(long n)
{
	long x;

	x = n;
	if (x < 0)
	{
		ft_putchar('-');
		x = x * -1;
	}
	if (x / 10 > 0)
	{
		ft_putnbr(x / 10);
	}
	ft_putchar((x % 10) + '0');
}
