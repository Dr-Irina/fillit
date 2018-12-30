/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <hrice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:10:28 by hrice             #+#    #+#             */
/*   Updated: 2018/12/27 16:10:28 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	//t_list	*list_tetri;
	char	*tetri;
	//t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((tetri = read_file(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error1\n");
		return (0);
	}
	if (!test_file(tetri))
	{
		ft_putstr("error2\n");
		return (0);
	}
	/*tetri_list = get_tetri_list(tetris);
	map = solve_map(list_tetri);
	print_map(map);
	free_map(map);
	free_list(list_tetri);*/
	return (1);
	/*fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, BUFF_SIZE)))
		buf[ret - 1] = '\0';
	if (!test_one(buf))
	{
		ft_putendl("error test_one\n");
		return (0);
	}
	if (!test_line(buf))
	{
		ft_putendl("error test_line");
		return (0);
	}
	return (1);*/
