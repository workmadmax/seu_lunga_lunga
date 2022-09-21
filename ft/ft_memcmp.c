/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:06:04 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/27 18:25:38 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
    size_t          i;
    unsigned char   *s1;
    unsigned char   *s2;

    i = 0;
    s1 = (unsigned char *)str1;
    s2 = (unsigned char *)str2;
    while (i < n)
    {
        if (s1[i] != s2[i])
            return ((int)(s1[i] - s2[i]));
        if (n == 0)
            return ((int)n);
        i++;
    }
    return (0);
}
