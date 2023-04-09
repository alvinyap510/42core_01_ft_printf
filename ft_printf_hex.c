/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyap <alyap@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:52:43 by alyap             #+#    #+#             */
/*   Updated: 2023/04/09 17:16:51 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_hex_digits(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	ft_get_hex_char(unsigned long long n, char format)
{
	char	hex_char;

	if (n % 16 < 10)
			hex_char = '0' + (n % 16);
	else
	{
		if (format == 'x')
			hex_char = 'a' + (n % 16) - 10;
		else
				hex_char = 'A' + (n % 16) - 10;
	}
	return (hex_char);
}

int	ft_print_hex(unsigned long long n, char format)
{
	char	*hex_str;
	int		len;
	int		count;

	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	len = ft_hex_digits(n);
	hex_str = malloc(sizeof(char) * (len + 1));
	if (!hex_str)
		return (0);
	ft_bzero(hex_str, len + 1);
	while (n > 0)
	{
		hex_str[len - 1] = ft_get_hex_char(n, format);
		n /= 16;
		len--;
	}
	count = ft_print_str(hex_str);
	free(hex_str);
	return (count);
}
