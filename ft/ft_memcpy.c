/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:43:10 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/27 18:25:42 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t          i;
    unsigned char   *mdest;
    unsigned char   *msrc;

    if (dest == NULL && src == NULL)
        return (NULL);
    mdest = (unsigned char *)dest;
    msrc = (unsigned char *)src;
    i = 0;
    while (i < n)
    {
        mdest[i]= msrc[i];
        i++;
    }
    return (dest);
}