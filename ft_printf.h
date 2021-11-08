/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:15:59 by fasad             #+#    #+#             */
/*   Updated: 2021/11/08 20:19:50 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_putstr(char *str, int ret);
int		ft_putchar(char c, int ret);
int		ft_putnbr(long n, int ret);
int		ft_puthex(unsigned long long n, int ret);
int		ft_puthex_ui(unsigned int num, int k, int ret);
int		xc_func(unsigned int xc, char c, int ret);
int		pc_func(unsigned long long pc, int ret);
int		u_func(unsigned int u, int ret);
int		ft_printf(const char *str, ...);
int		check_spec(char c, va_list args, int ret);
int		printer(char *str, va_list args);
#endif
