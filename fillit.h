/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <hrice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:51:38 by hrice             #+#    #+#             */
/*   Updated: 2018/12/30 20:42:06 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_map{
	int				size;
	char			**content;
}					t_map;

typedef struct		s_point;{
	int 			x;
	int 			y;
}					t_point;

typedef struct		s_tetris{
	char 			**pos;
	int 			height;
	int 			width;
	char 			letter;
}					t_tetris;

#endif
