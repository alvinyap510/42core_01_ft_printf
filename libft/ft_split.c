/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyap <alyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:29:19 by alyap             #+#    #+#             */
/*   Updated: 2022/04/20 14:32:31 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_splits(char *str, char c)
{
	size_t	split_counter;
	size_t	is_word;
	size_t	i;

	split_counter = 0;
	is_word = 0;
	i = 0;
	while (str[i])
	{
		if (is_word == 0 && str[i] != c)
		{
			is_word = 1;
			split_counter++;
		}
		if (is_word == 1 && str[i] == c)
			is_word = 0;
		i++;
	}
	return (split_counter);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	d1;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (ft_count_splits((char *)s, c) + 1));
	if (!ret)
		return (NULL);
	d1 = 0;
	i = 0;
	while (d1 < ft_count_splits((char *)s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		ret[d1] = ft_substr(s, start, i - start);
		d1++;
		i++;
	}
	ret[d1] = NULL;
	return (ret);
}
