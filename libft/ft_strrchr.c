/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyap <alyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:01:28 by alyap             #+#    #+#             */
/*   Updated: 2022/04/19 22:45:23 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	rev;

	rev = ft_strlen(s);
	while (rev >= 0)
	{
		if (s[rev] == (unsigned char)c)
			return ((char *)(s + rev));
		rev--;
	}
	return (NULL);
}
