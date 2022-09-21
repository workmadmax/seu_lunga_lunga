/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:48:43 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/27 18:52:35 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
    A função copia 'n' caracteres de str2, para str1, para bloco de memória sobrepostos
    memove é uma abordagem mais segura que memcpy();
*/
#include "libft.h"

void    *ft_memmove(void *str1, const void *str2, size_t n)
{
    char    *dest;
    char    *src;

    dest = (char *)str1;
    src = (char *)str2;

    if (dest < src)
    {
        while (n > 0)
        {
            dest[n] = src[n];
            n--;
        }
        return (dest);
    }
    else
        ft_memcpy(dest, src, n);
    return (dest);
}