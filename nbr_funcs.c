/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:14:42 by joseoliv          #+#    #+#             */
/*   Updated: 2024/05/02 23:34:40 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long n, char upper)
{
	char	*hexa_nums;
	char	result;
	int		len;

	hexa_nums = ft_strdup("0123456789abcdef");
	len = count(n, 16);
	if (n >= 16)
		ft_putnbr_hexa(n / 16, upper);
	if (upper == 'x')
		ft_putchar(hexa_nums[n % 16]);
	else
	{
		result = hexa_nums[n % 16];
		ft_putchar(ft_toupper(result));
	}
	free(hexa_nums);
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	if (!n)
	{
		len = ft_putstr("(null)");
		return (len);
	}
	if (n == -2147483648)
	{
		len = ft_putstr("-2147483648");
		return (len);
	}
	len = count(n, 10);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
	return (len);
}

int	ft_putptr_hexa(unsigned long n)
{
	int	len;

	if (n == 0)
	{
		len = ft_putstr("(nil)");
		return (len);
	}
	else
	{
		len = ft_putstr("0x");
		len += ft_putnbr_hexa(n, 'x');
	}
	return (len);
}

int	count(long n, int base)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > base)
	{
		n /= base;
		i++;
	}
	return (i);
}
