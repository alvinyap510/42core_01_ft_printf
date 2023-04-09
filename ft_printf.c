/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyap <alyap@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:52:55 by alyap             #+#    #+#             */
/*   Updated: 2023/04/09 17:06:46 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(const char *format, va_list args, int i)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (format[i] == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (format[i] == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (format[i] == 'u')
		count += ft_print_uint(va_arg(args, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), format[i]);
	else if (format[i] == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format || !*format)
		return (0);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			count += ft_print_char(format[i]);
			i++;
		}
		else
		{
			count += ft_parse(format, args, i + 1);
			i += 2;
		}
	}
	va_end(args);
	return (count);
}
