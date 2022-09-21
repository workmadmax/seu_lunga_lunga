/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:34:44 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/28 15:11:10 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  len;

    if (s1 == NULL || set == NULL)
        return (NULL);
    while (*s1 && ft_strchr(set, *s1))
        s1++;
    len = ft_strlen(s1);
    while (len && ft_strchr(set, s1[len]))
        len--;
    return (ft_substr(s1, 0, len + 1));
}
