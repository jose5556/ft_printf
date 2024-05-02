/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_put_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:14:42 by joseoliv          #+#    #+#             */
/*   Updated: 2024/05/02 19:26:40 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa_fd(unsigned int n, char upper, int len)
{
	char	*hexa_nums;
	char	result;

	hexa_nums = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ft_putnbr_hexa_fd(n / 16, upper, len);
	}
	if (upper == 'x')
	{
		ft_putchar_fd(hexa_nums[n % 16]);
		len++;
	}
	else
	{
		result = hexa_nums[n % 16];
		ft_putchar_fd(ft_toupper(result));
		len++;
	}
	free(hexa_nums);
	return (len);
}

int	ft_putnbr_hexa_unsigned_fd(unsigned long n, int len)
{
	char	*hexa_nums;

	hexa_nums = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ft_putnbr_hexa_unsigned_fd((n / 16), len);
	}
	ft_putchar_fd(hexa_nums[n % 16]);
	len++;
	free(hexa_nums);
	return (len);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int len)
{
	if (n > 9)
		ft_putnbr_unsigned_fd(n / 10, len);
	ft_putchar_fd(n % 10 + 48);
	len++;
	return (len);
}

int	ft_putnbr_fd(int n, int len)
{
	if (n == -2147483648)
	{
		len =+ ft_putstr_fd("-2147483648", len);
		return (len);
	}
	if (n < 0)
	{
		ft_putchar_fd('-');
		n *= -1;
		len++;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, len);
	ft_putchar_fd(n % 10 + 48);
	len++;
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
