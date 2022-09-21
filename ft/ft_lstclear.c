/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:54:25 by mdouglas          #+#    #+#             */
/*   Updated: 2022/04/29 10:55:58 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **list, void (*del)(void *))
{
    t_list  *temp;
    
    if (!list)
        return ;
    while ((*list))
    {
        temp = (*list)->next;
        ft_lstelone(*list, del);
        (*list) = temp;
    }
    list = NULL;
}
