/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:17:03 by joseoliv          #+#    #+#             */
/*   Updated: 2024/04/30 22:27:00 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd);

void	call_funcs(va_list args, char c);

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			call_funcs(args, str[++i]);
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}

void	call_funcs(va_list args, char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_hexa_unsigned_fd(va_arg(args, unsigned long), 1);
	}
	else if (c == 'x' || c == 'X')
		ft_putnbr_hexa_fd(va_arg(args, unsigned int), 1, c);
}
