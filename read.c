/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <hrice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:13:20 by hrice             #+#    #+#             */
/*   Updated: 2019/01/08 15:31:52 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "Libft/libft.h"

/* Считываем поданные мапы с тетроминошкамии и проверяем. Если считалось больше
 * 20 символов, значит подано несколько тетроминошек, следовательно, надо
 * проверить, чтоб их количество было меньше или равно 26, иначе не сможем
 * заменить их все на буквы. 546 = 26 (кол-во тетроминошек)* 20 (количество
 * символов в одное тетроминошке 4х4 со \n) + 25 (\n между * поданными
 * тетроминошками) + 1 (на \0 в конце) */

char	*read_file(int fd)
{
	char	*tetris;
	char	*buffer;
	int		ret;

	buffer = ft_strnew(21);
	if ((fd < 0 || read(fd, buffer, 0) < 0))
		return (NULL);
	tetris = ft_strnew(0);
	while ((ret = read(fd, buffer, 21)) >= 20)
	{
		buffer[ret] = '\0';
		tetris = ft_strjoin(tetris, buffer);
		if (ft_strlen(tetris) > 546)
			return (NULL);
	}
	ft_memdel((void**)&buffer);
	tetris = ft_strjoin(tetris, "\0");
	return (tetris);
}

t_list          *tetri_list(char *tetris)
{
    int         i;
    char        c;
    t_list      *tetri_list;
    t_tetris    *tetri;

    tetri_list = NULL;
    tetri = NULL;
    c = 'A';
    i = 0;
    while (tetris[i])
    {
        tetri = get_block(tetris[i], c);
        ft_lstadd(tetri_list, ft_lstnew(tetri, sizeof(t_tetris)));
        i += 19;
        if (tetris[i + 1] = '\n')
            i += 2;
        else
            break;
        c++;
    }
    ft_lstrev(tetri_list);
    return(tetri_list);
}
