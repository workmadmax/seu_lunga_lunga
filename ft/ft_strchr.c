/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:33:05 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/29 10:57:19 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    A função procura a primeira ocorrência do caractere c(unsigned char)
    na string apontada pelo argumento str.
*/

#include "libft.h"

char    *ft_strchr(const char *str, int c)
{
    int     i;
    char    *s;

    i = 0;
    s = (char *)str;
    while (s[i])
    {
        if (s[i] == c)
            return (&s[i]);
        i++;
    }
    if (c == '\0')
        return (&s[i]);
    return (0);
}
