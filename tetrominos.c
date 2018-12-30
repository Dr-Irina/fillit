/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrominos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <hrice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 19:37:18 by hrice             #+#    #+#             */
/*   Updated: 2018/12/30 21:00:42 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris        *create_tetri(char **pos, int height, int width)
{
    t_tetris    *tetris;

    if (!(tetris = ft_memalloc(sizeof(t_tetris))))
        return (NULL);
    tetris->pos = pos;
    tetris->height = height;
    tetris->width = width;
    tetris->letter = letter;
    return (tetris);
}

t_point         *create_point(int x, int y)
{
    t_point     *point;

    if (!(point = ft_memalloc(sizeof(t_point))))
        return (NULL);
    point->x = x;
    point->y = y;
    return (point);
}


