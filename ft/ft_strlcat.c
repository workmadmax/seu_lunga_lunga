/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:11:38 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/27 18:26:05 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t src_len;
    size_t dest_len;
    size_t index;

    src_len = ft_strlen(src);
    dest_len = ft_strlen(dest);
    index = 0;
    if (size <= dest_len || size == 0)
        return (src_len + size);
    while (src[index] && dest_len < (size - 1))
    {
        dest[dest_len] = src[index];
        dest_len++;
        index++;
    }
    dest[dest_len] = '\0';
    return (src_len + dest_len - index);
}
