/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:17:03 by joseoliv          #+#    #+#             */
/*   Updated: 2024/05/02 19:28:48 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len = call_funcs(args, str[++i]);
		else
		{
			ft_putchar_fd(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int	call_funcs(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int));
		len++;
	}
	else if (c == '%')
	{
		ft_putchar_fd('%');
		len++;
	}
	else if (c == 's')
		len = ft_putstr_fd(va_arg(args, char *), len);
	else if (c == 'i' || c == 'd')
		len = ft_putnbr_fd(va_arg(args, int), len);
	else if (c == 'u')
		len = ft_putnbr_unsigned_fd(va_arg(args, unsigned int), len);
	else if (c == 'p')
	{
		len = ft_putstr_fd("0x", len);
		len = ft_putnbr_hexa_unsigned_fd(va_arg(args, unsigned long), len);
	}
	else if (c == 'x' || c == 'X')
		len = ft_putnbr_hexa_fd(va_arg(args, unsigned int), c, len);
	return (len);
}
