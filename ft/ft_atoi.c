/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:50:40 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/29 10:50:57 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_checkspace(char c)
{
    if (c == '\t'
        || c == '\v'
        || c == '\r'
        || c == '\n'
        || c == '\f'
        || c == ' ')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int neg;
    int res;

    neg = 0;
    res = 0;
    while (ft_checkspace(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            neg = 1;
        str++;
    }
    while (ft_isdigit(*str))
        res = (res * 10) + (*str++ -48);
    if (neg)
        return (res * -1);
    return (res);
}
