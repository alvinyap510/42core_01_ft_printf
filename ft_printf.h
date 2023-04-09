/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyap <alyap@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:53:00 by alyap             #+#    #+#             */
/*   Updated: 2023/04/09 17:04:37 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_parse(const char *format, va_list args, int i);

void	ft_putchar(char c);
int		ft_print_char(int nbr);
int		ft_print_str(char *str);

int		ft_print_nbr(int n);
int		ft_uint_digits(unsigned int n);
int		ft_print_uint(unsigned int n);

int		ft_hex_digits(unsigned long long n);
int		ft_print_hex(unsigned long long n, char format);

int		ft_print_ptr(unsigned long long ptr);

#endif