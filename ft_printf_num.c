/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyap <alyap@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:52:48 by alyap             #+#    #+#             */
/*   Updated: 2023/04/09 17:08:21 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_nbr_digits(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int ft_print_nbr(int n)
{
	int count;
	char *num;

	count = 0;
	num = ft_itoa(n);
	count = ft_print_str(num);
	free(num);
	return (count);
}

int ft_uint_digits(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int ft_print_uint(unsigned int n)
{
	char *uint_str;
	int len;
	int count;

	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	len = ft_uint_digits(n);
	uint_str = malloc(sizeof(char) * (len + 1));
	if (!uint_str)
		return (0);
	ft_bzero(uint_str, len + 1);
	while (n > 0)
	{
		uint_str[len - 1] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	count = ft_print_str(uint_str);
	free(uint_str);
	return (count);
}
