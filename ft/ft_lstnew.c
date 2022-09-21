/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:52:13 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/29 10:56:16 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *new_elem;

    new_elem = malloc(sizeof(t_list));
    if (new_elem == NULL)
        return (NULL);
    new_elem->content = content;
    new_elem->next = NULL;
    return (new_elem);
}
