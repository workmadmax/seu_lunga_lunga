/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:01:54 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/29 12:16:36 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
    A função copia o caractere 'c'(um unsigned char) para os primeiros 'n' caracteres
    da string apontada, pelo argumento 'str'.
    Retorna um ponteiro para a área de memória 'str'.
*/

void    *ft_memset(void *s, int c, size_t n)
{
    char        *aux;
    size_t      i;

    aux = (char *)s;
    i = 0;
    while (i < n)
    {
        aux[i] = c;
        i++;
    }
    return (s);
}
