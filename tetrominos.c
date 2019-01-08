/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrominos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <hrice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 19:37:18 by hrice             #+#    #+#             */
/*   Updated: 2019/01/04 17:54:15 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris        *create_tetri(char **pos, int height, int width, char letter)
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

void            min_max(char *tetri, t_point *min, t_point *max)
{
    int         i;

    i = 0;
    while (i < 20)
    {
        if (tetri[i] == '#')
        {
            if (min->x > i % 5)
                min->x = i % 5;
            if (min->y > i / 5)
                min->y = i / 5;
            if (max->x < i % 5)
                max->x = i % 5;
            if (max->y < i / 5)
                max->y = i / 5;
        }
        i++;
    }
}

t_tetris        *get_block(char *tetri, char c)
{
    int         i;
    t_point     *min;
    t_point     *max;
    t_tetris    *content;
    char        **pos;

    i = 0;
    min = create_point(3, 3);
    max = create_point(0, 0);
    min_max(tetri, min, max);
    pos = ft_memalloc(sizeof(char *) * (max->y - min->y) + 1);
    while (i < max->y - min->y + 1)
    {
        pos[i] = ft_strnew((max->x - min->x) + 1);
        ft_memcpy(pos[i], tetri[min->x + (i + min->y) * 5],
                  (max->x - min->x) + 1);
        i++;
    }
    content = create_tetri(pos, (max->y - min->y + 1),
                            (max->x - min->x +1), c);
    ft_memdel((void**)&min);
    ft_memdel((void**)&max);
}

t_list          free_tetri(t_list *list_tetri)
{
    int         i;
    t_tetris    *tetri;
    t_tetris    *next;

    i = 0;
    while(list_tetri)
    {
        tetri = (t_tetris*)list_tetri->content;
        next = list_tetri->next;
        while (i < tetri->height)
        {
            ft_memdel((void**)&tetri->pos[i]);
            i++;
        }
        ft_memdel(void**(&list_tetri));
        list_tetri = next;
    }
    return (NULL);
}
