/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:15:12 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/27 18:26:23 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    A função checa a última ocorrência do caractere 'c'(unsigned char) na string 
    apontada pelo argumento 'str'.
    Retorna um ponteiro para a última ocorrencia do caractere em 'str'. Se não
    for encontrado valor retorna 'null'.
*/

#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{;
    int     i;

    i = 0;
    while (str[i])
        i++;
    while (i >= 0)
    {
        if (str[i] == (char)c)
            return ((char *)(str + i));
        i--;
    }
    return (NULL);
}