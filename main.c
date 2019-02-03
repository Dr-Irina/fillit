/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 12:20:49 by wned              #+#    #+#             */
/*   Updated: 2019/01/31 17:02:54 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	char	*str;
	t_list	*tetri_list;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((str = read_file(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!is_filevalid(str))
	{
		ft_putstr("error\n");
		return (0);
	}
	tetri_list = get_tetri_list(str);
	map = solve(tetri_list);
	print_map(map);
	free_map(map);
	free_all_tetri(tetri_list);
	return (1);
}
