/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_assist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:36:29 by fasad             #+#    #+#             */
/*   Updated: 2021/11/08 20:13:42 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ui(unsigned int num, int k, int ret)
{
	unsigned int	rem;
	int				i;

	i = 0;
	rem = 0;
	if (num != 0)
	{
		rem = num % 16;
		ret = ft_puthex_ui(num / 16, k, ret);
		if (rem < 10)
			ret = ft_putchar(rem + 48, ret);
		else
		{
			if (k == 0)
				ret = ft_putchar(rem + 55 + 32, ret);
			else
				ret = ft_putchar(rem + 55, ret);
		}
	}
	return (ret);
}

int	ft_puthex(unsigned long long num, int ret)
{
	unsigned long int	rem;
	int					i;

	i = 0;
	rem = 0;
	if (num != 0)
	{
		rem = num % 16;
		ret = ft_puthex(num /= 16, ret);
		if (rem < 10)
			ret = ft_putchar(rem + 48, ret);
		else
		{
			ret = ft_putchar(rem + 55 + 32, ret);
		}
	}
	return (ret);
}

int	xc_func(unsigned int xc, char c, int ret)
{
	if (xc == 0)
		ret = ft_putchar('0', ret);
	else
	{
		if (c == 'x')
			ret = ft_puthex_ui(xc, 0, ret);
		else
			ret = ft_puthex_ui(xc, 1, ret);
	}
	return (ret);
}

int	pc_func(unsigned long long pc, int ret)
{
	ret = ft_putstr("0x", ret);
	if (pc == 0)
		ret = ft_putchar('0', ret);
	else
		ret = ft_puthex(pc, ret);
	return (ret);
}

int	u_func(unsigned int u, int ret)
{
	if (u < 0)
		u = 4294967296 + u;
	ret = ft_putnbr(u, ret);
	return (ret);
}
