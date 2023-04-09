/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyap <alyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:29:36 by alyap             #+#    #+#             */
/*   Updated: 2022/04/19 22:10:04 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	nbr;
	int		len;

	nbr = (long)n;
	len = count_len(nbr);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len--] = '\0';
	if (nbr == 0)
		ret[0] = '0';
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		ret[len] = '0' + (nbr % 10);
		nbr /= 10;
		len--;
	}
	return (ret);
}
