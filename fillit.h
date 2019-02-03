/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 12:44:29 by wned              #+#    #+#             */
/*   Updated: 2019/01/31 17:12:15 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef	struct	s_map
{
	int			size;
	char		**content;
}				t_map;

typedef struct	s_tetri
{
	char		**pos;
	int			height;
	int			width;
	char		letter;
}				t_tetri;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

int				is_filevalid(char *tetris);
char			*read_file(int file);
t_list			*get_tetri_list(char *tetris);
void			print_map(t_map *map);
t_map			*create_map(int size);
void			free_map(t_map *map);
int				place_tetri(t_map *map, t_tetri *tetri, int x, int y);
void			setchar_tetri(t_map *map, t_tetri *t, t_point *point, char c);
t_point			*create_point(int x, int y);
t_tetri			*get_block(char *tetris, char c);
t_list			*free_all_tetri(t_list *lst_tetri);
t_map			*solve(t_list *lst);

#endif
