/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:04:59 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/27 18:25:59 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    A função é usada para duplicar uma string.
    Retorna um ponteiro para uma string de bytes terminada em nulo.
*/

#include "libft.h"

char    *ft_strdup(const char *s)
{
    char    *ret;
    size_t  size;
    
    size = ft_strlen(s) + 1;
    ret = (char *)malloc(size);
    if (ret == NULL)
        return (NULL);
    ft_strlcpy(ret, s, size);
    return (ret);
}
