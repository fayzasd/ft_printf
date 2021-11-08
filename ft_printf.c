/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:14:23 by fasad             #+#    #+#             */
/*   Updated: 2021/11/08 20:17:32 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_spec(char c, va_list args, int ret)
{
	if (c == 'c')
		ret = ft_putchar(va_arg(args, int), ret);
	else if (c == 's')
		ret = ft_putstr(va_arg(args, char *), ret);
	else if (c == 'd' || c == 'i')
		ret = ft_putnbr(va_arg(args, int), ret);
	else if (c == 'u')
		ret = u_func(va_arg(args, unsigned int), ret);
	else if (c == 'p')
		ret = pc_func(va_arg(args, unsigned long long), ret);
	else if (c == 'x')
		ret = xc_func(va_arg(args, unsigned int), c, ret);
	else if (c == 'X')
		ret = xc_func(va_arg(args, unsigned int), c, ret);
	else if (c == '%')
		ret = ft_putchar('%', ret);
	return (ret);
}

int	printer(char *str, va_list args)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret = check_spec(str[i + 1], args, ret);
			i++;
		}
		else
			ret = ft_putchar(str[i], ret);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	char	*store;
	va_list	args;
	int		ret;

	va_start(args, str);
	ret = 0;
	if (!str)
		return (0);
	ret += printer((char *)str, args);
	va_end(args);
	return (ret);
}
