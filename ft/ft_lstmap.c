/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:35:14 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/27 18:25:25 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
    t_list  *listmap;
    t_list  *temp;
    void    *content;

    if (!list)
        return (NULL);
    listmap = NULL;
    while (list)
    {
        content = f(list->content);
        temp = ft_lstnew(content);
        if (!temp)
        {
            ft_lstclear(&listmap, del);
            return (NULL);
        }
        ft_lstadd_back(&listmap, temp);
        list = list->next;
    }
    return (listmap);
}
