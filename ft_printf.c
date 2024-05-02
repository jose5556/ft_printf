/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:17:03 by joseoliv          #+#    #+#             */
/*   Updated: 2024/05/02 23:26:14 by joseoliv         ###   ########.fr       */
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
			len += call_funcs(args, str[++i]);
		else
		{
			ft_putchar(str[i]);
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
		len += ft_putchar(va_arg(args, int));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'p')
		len += ft_putptr_hexa(va_arg(args, unsigned long));
	else if (c == 'x' || c == 'X')
		len += ft_putnbr_hexa(va_arg(args, unsigned int), c);
	return (len);
}
