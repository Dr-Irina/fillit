/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:31:23 by wned              #+#    #+#             */
/*   Updated: 2019/01/31 17:35:04 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*get_tetri_list(char *str)
{
	int		i;
	char	c;
	t_list	*tetri_list;
	t_tetri *tetri;

	tetri_list = NULL;
	tetri = NULL;
	c = 'A';
	i = 0;
	while (str[i])
	{
		tetri = get_block(&str[i], c);
		ft_lstadd(&tetri_list, ft_lstnew(tetri, sizeof(t_tetri)));
		i += 19;
		if (str[i + 1] == '\n')
			i += 2;
		else
			break ;
		c++;
	}
	ft_lst_rev(&tetri_list);
	return (tetri_list);
}
