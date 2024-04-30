/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_put_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:14:42 by joseoliv          #+#    #+#             */
/*   Updated: 2024/04/30 22:27:21 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa_fd(unsigned int n, int fd, char upper)
{
	char	*hexa_nums;
	char	result;

	hexa_nums = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ft_putnbr_hexa_fd(n / 16, fd, upper);
	}
	if (upper == 'x')
	{
		ft_putchar_fd(hexa_nums[n % 16], fd);
	}
	else
	{
		result = hexa_nums[n % 16];
		ft_putchar_fd(ft_toupper(result), fd);
	}
	free(hexa_nums);
}

void	ft_putnbr_hexa_unsigned_fd(unsigned long n, int fd)
{
	char	*hexa_nums;

	hexa_nums = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ft_putnbr_hexa_unsigned_fd((n / 16), fd);
	}
	ft_putchar_fd(hexa_nums[n % 16], fd);
	free(hexa_nums);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
