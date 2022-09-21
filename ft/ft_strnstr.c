/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:15:23 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/27 18:26:19 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  i;
    size_t  c;
    
    if (little[0] == '\0')
        return ((char *)little);
    i = 0;
    while (little[i] != '\0' && i < len)
    {
        c = 0;
        while ((little[i + c] == big[c]) && (i + c) < len)
        {
            if (big[c + 1] == '\0')
                return ((char *)(&little[i]));
            c++;
        }
        i++;
    }
    return (NULL);
}
