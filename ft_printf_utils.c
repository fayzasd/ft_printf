/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:14:50 by fasad             #+#    #+#             */
/*   Updated: 2021/11/08 20:14:45 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int ret)
{
	ret++;
	write(1, &c, 1);
	return (ret);
}

int	ft_putstr(char *s, int ret)
{	
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
			ret++;
		}
	}
	else
		ret = ft_putstr("(null)", ret);
	return (ret);
}

int	ft_putnbr(long n, int ret)
{
	long	x;

	x = n;
	if (x < 0)
	{
		ret = ft_putchar('-', ret);
		x = x * -1;
	}
	if (x / 10 > 0)
	{
		ret = ft_putnbr(x / 10, ret);
	}
	ret = ft_putchar((x % 10) + '0', ret);
	return (ret);
}
