/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:57:08 by mdouglas          #+#    #+#             */
/*   Updated: 2022/09/24 03:23:27 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	slen = ft_strlen(src);
	sub = (char *)src;
	if (start >= slen)
		sub = malloc(1);
	else if (len >= slen)
		sub = malloc(slen - start + 1);
	else
		sub = (char *)malloc(len + 1);
	if (!sub)
		return (sub);
	i = 0;
	while (i < len && start < slen)
	{
		sub[i] = src[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}