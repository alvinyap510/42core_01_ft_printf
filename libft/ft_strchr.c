/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyap <alyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:59:37 by alyap             #+#    #+#             */
/*   Updated: 2022/04/20 14:07:03 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	x;
	char	*ptr;

	x = (char)c;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == x)
			return (ptr);
		ptr++;
	}
	if (!*ptr && c != 0)
		return (0);
	return (ptr);
}
