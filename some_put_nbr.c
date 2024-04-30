/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_put_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:14:42 by joseoliv          #+#    #+#             */
/*   Updated: 2024/04/30 22:17:38 by joseoliv         ###   ########.fr       */
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