/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <hrice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:25:20 by hrice             #+#    #+#             */
/*   Updated: 2018/12/26 16:45:51 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*size это size * size >= list_count(lst) * 4
значение size находим в функции _____________
В функции create_map выделяем память для карты размером size построчно, заполняем катру точками*/
t_map		*create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if (!(map->content = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	map->size = size;
	while (i < size)
	{
		if (!(map->content[i] = ft_strnew(size)))
			return (NULL);
		while (j < size)
		{
			map->content[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

/*В функции free_map освобождаем выделенную память */
void		free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		free (map->content[i]);
		i++;
	}
	free(map->content);
	free (map);
}

/*В функции print_map выводим построчно карту*/
void		print_map(t_map *map)
{
	int		i;
	
	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->content[i]);
		write(1, "\n", 1);
		i++;
	}
}

