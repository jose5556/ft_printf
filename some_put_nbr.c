/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_put_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:14:42 by joseoliv          #+#    #+#             */
/*   Updated: 2024/05/02 21:21:34 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned int n, char upper)
{
	char	*hexa_nums;
	char	result;
	int 	len;

	hexa_nums = ft_strdup("0123456789abcdef");
	len = count(n, 16);
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16, upper);
	}
	if (upper == 'x')
	{
		ft_putchar(hexa_nums[n % 16]);
	}
	else
	{
		result = hexa_nums[n % 16];
		ft_putchar(ft_toupper(result));
	}
	free(hexa_nums);
	return (len);
}

int	count(int n, int base)
{
	int	i;

	i = 1;
	while (n > base)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	ft_putnbr_hexa_long(unsigned long n)
{
	char	*hexa_nums;
	int		len;

	hexa_nums = ft_strdup("0123456789abcdef");
	len = count(n, 16);
	if (n >= 16)
	{
		ft_putnbr_hexa_long((n / 16));
	}
	ft_putchar(hexa_nums[n % 16]);
	free(hexa_nums);
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
