/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:43:08 by mdouglas          #+#    #+#             */
/*   Updated: 2022/09/17 13:36:38 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

size_t  gnl_strlen(char *str)
{
    size_t  i;
    
    i = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *gnl_strchr(char *str, int c)
{
    int     i;
    char    x;

    i = 0;
    x = (char)c;
    if (!str || c == '\0')
        return (NULL);
    while ((str[i] != x) && (str[i] != '\0'))
        i++;
    if (str[i] == x)
        return ((char *)(str + i));
    return (NULL);
}

/*
    strjoin with free s1 "string 1";
*/

char    *gnl_strjoin(char *s1, char *s2)
{
    unsigned int    i;
    unsigned int    j;
    char            *str;

    i = 0;
    j = 0;
    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char));
        *s1 = '\0';
    }
    str = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
    if (!s2 || !str)
        return (NULL);
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++; 
    }
    while (s2[j] != '\0')
        str[i++] = s2[j++];
    str[i] = '\0';
    free(s1);
    return (str);
}

/*
    strdup with free 'str'
*/

char    *gnl_dup(char *str)
{
    char    *dup;
    int     i;
    int     j;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    dup = (char *)malloc(sizeof(char) * (gnl_strlen(str) - i + 1));
    if (!dup)
        return (NULL);
    i++;
    j = 0;
    while (str[i])
        dup[j++] = str[i++];
    dup[j] = '\0';
    free(str);
    return (dup);
}
