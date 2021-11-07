/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:14:23 by fasad             #+#    #+#             */
/*   Updated: 2021/11/07 20:52:47 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



char *ft_rev(char *str)
{
	char *temp;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	temp = (char *)malloc(sizeof(char) * i + 1);
	i--;
	while (i > 0)
	{
		temp[j] = str[i];
		j++;
		i--;
	}
	temp[j] = '\0';
	return temp;
}

int nbr_len(long num)
{
	int i;

	i = 0;
	if (num < 0)
		num = -(num);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return i;
}

void ft_puthex(long num)
{
	char *hex;
	long rem;
	int i;

	i = 0;
	rem = 0;
	hex = (char *)malloc(sizeof(char) * nbr_len(num) + 1);
	while (num != 0)
	{
		rem = num % 16;
		if (rem < 10)
		{
			hex[i] = rem + 48;
			i++;
		}
		else
		{
			hex[i] = rem + 55;
			i++;
		}
		num /= 16;
	}
	ft_putstr(ft_tolower(ft_rev(hex)));
}

int check_spec(char c, va_list args)
{
	int ret;
	long i;

	i = 0;
	ret = 0;
	/*
	char *spec = "cspdiuxX\n";
	while (*spec != '\n')
	{
		if (c == *spec)
			ret++;
		spec++;
	}*/
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
	{
		i = va_arg(args, int);
		if (i < 0)
			i = 4294967296 + i;
		ft_putnbr(i);
	}
	else if (c == 'p')
	{
		long addr;
		addr = (long)va_arg(args,void  *);
		ft_putstr("0x");
		ft_puthex(addr);
		ft_putchar('0');
	}
	else if (c == 'x')
	{
		ft_puthex(va_arg(args, int));
	}
	return ret;
}

int printer(char *str, va_list args)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += check_spec(str[i+1], args);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
		ret++;
	}
	return 0; 
}

int	ft_printf(const char *str, ...)
{
	char	*store;
	va_list args;
	int ret;

	va_start(args, str);	
	ret = 0;
	if (!str)
		return (0);
	ret += printer((char *)str, args);
	va_end(args);
	return (ret);
}

int main(){
	char c = 'a';
	int i = 12345;
	char *s = "epicity";
	void *p = malloc(1);

	ft_printf("ft_printf --  %x \n",i);
	printf("printf -- %x ",i);
}