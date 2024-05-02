/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:16:23 by joseoliv          #+#    #+#             */
/*   Updated: 2024/05/02 21:20:46 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
int		ft_putnbr_hexa(unsigned int n, char upper);
int		ft_putnbr_hexa_long(unsigned long n);
int		ft_putchar(char c);
int		ft_putnbr(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
int		ft_putstr(char *s);
int		call_funcs(va_list args, char c);
int		count(int n, int base);

#endif