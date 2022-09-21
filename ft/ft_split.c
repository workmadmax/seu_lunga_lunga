/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:16:54 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/28 15:31:48 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t   total_words(char const *s, char sep);
static char *ft_my_strcpy(char *dest, char *src, size_t *len);
static char **create_words(char **split, const char *s, char c, size_t i);

char    **ft_split(char const *s, char c)
{
    char        **split;
    size_t      i;

    if (!s)
        return (NULL);
    split = (char **)malloc(sizeof(char *) * (total_words(s, c) + 1));
    if (!split)
        return (NULL);
    i = 0;
    split = create_words(split, s, c, i);
    if (!split)
        return(NULL);
    return (split);
}

static char **create_words(char **split, const char *s, char c, size_t i)
{
    char    *start;
    size_t  word_len;

    word_len = 0;
    while (*s)
    {
        while (*s && *s == c)
            s++;
        if (*s && *s != c)
        {
            start = (char *)s;
            while (*s && *s != c)
            {
                word_len++;
                s++;
            }
            split[i] = (char *)malloc(sizeof(char) * (word_len + 1));
            if (!split[i])
                return (NULL);
            ft_my_strcpy(split[i++], start, &word_len);
        }
    }
    split[i] = NULL;
    return (split);
}

static char *ft_my_strcpy(char *dest, char *src, size_t *len)
{
    size_t  i;
    
    i = 0;
    while (i < *len)
    {
        *dest = src[i];
        i++;
        dest++;
    }
    *dest = '\0';
    *len = 0;
    return (dest);
}

static size_t   total_words(char const *s, char sep)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (count);
	if (!ft_strchr(s, sep))
		return (1);
	while (*s)
	{
		while (*s && *s == sep)
			s++;
		if (*s && *s != sep)
		{
			while (*s && *s != sep)
				s++;
			count++;
		}
	}
	return (count);
}
