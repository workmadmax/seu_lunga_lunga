/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:53 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/27 18:25:35 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *ptr, int c, size_t len)
{
    unsigned char   *str;
    
    while (len-- > 0)
    {
        str = (unsigned char *)ptr;
        if (*str == (unsigned char) c)
            return (str);
        ptr++;
    }
    return (NULL);
}
