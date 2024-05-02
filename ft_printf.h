/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:16:23 by joseoliv          #+#    #+#             */
/*   Updated: 2024/05/02 19:29:16 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
int		ft_putnbr_hexa_fd(unsigned int n, char upper, int len);
int		ft_putnbr_unsigned_fd(unsigned int n, int len);
int		ft_putnbr_hexa_unsigned_fd(unsigned long n, int len);
void	ft_putchar_fd(char c);
int		ft_putnbr_fd(int n, int len);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
int		ft_putstr_fd(char *s, int len);
int		call_funcs(va_list args, char c);

#endif