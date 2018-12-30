/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:14:52 by hrice             #+#    #+#             */
/*   Updated: 2018/12/02 20:59:17 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*last_list;
	t_list	*next_list;

	last_list = *alst;
	while (last_list)
	{
		next_list = last_list->next;
		del(last_list->content, last_list->content_size);
		free(last_list);
		last_list = next_list;
	}
	*alst = NULL;
}
