/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <hrice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:07:41 by hrice             #+#    #+#             */
/*   Updated: 2019/01/08 15:24:39 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list      *ft_lstrev(t_list **alst)
{
    t_list  *prev;
    t_list  *cur;
    t_list  *next;

    prev = NULL;
    cur = *alst;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *alst = prev;
}