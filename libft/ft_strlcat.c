/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyap <alyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:00:05 by alyap             #+#    #+#             */
/*   Updated: 2022/04/19 22:56:39 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	j = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = dstlen;
	if (!dstsize)
		return (srclen);
	if (dstsize < dstlen)
		return (srclen + dstsize);
	while (src[j] && i < dstsize)
		dst[i++] = src[j++];
	if (i == dstsize)
		i--;
	if (dstlen < dstsize)
		dst[i] = '\0';
	return (srclen + dstlen);
}
