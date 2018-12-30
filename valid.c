/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <hrice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:11:41 by hrice             #+#    #+#             */
/*   Updated: 2018/12/27 19:07:02 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

/*int		test_char(char *str)
{
	int i;
	int sharp;
	int point;
	int endline;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			point++;
		if (str[i] == '#')
			sharp++;
		if (str[i] == '\n')
			endline++;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		i++;
	}
	if (point == 12 && sharp == 4 && endline == 4)
		return (1);
	return (0);
}*/

/*int		test_file(char *s)
{
	int i;
	int j;

	if (!s)
	    return (0);
	if (ft_strlen(s) < 20)
	    return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == 20)
			break ;
	    if (((i + 1) % 5 == 0) && s[i] != '\n')
		{
			ft_putnbr(i);
			ft_putchar(s[i]);
			ft_putstr("ok2!");
	        return (0);
		}
	    if (((i + 1) % 5 != 0) && (!(s[i] != '.' || s[i] != '#')))
		{
			ft_putstr("ok3");
	        return (0);
		}
	    if (s[i] == '#')
		{
	        j++;
			ft_putnbr(j);
		}
	    i++;
	}
	if (!(s[20] == '\n' || s[20] == '\0') || j != 4)
	{
	    return (0);
		ft_putstr("ok1");
	}
	if (j == 4 && sharp_connection(s))
	{
		if (((s[i] == '\n' && s[i - 1] == '\n') || s[i] == '\0')
								&& j == 4 && i == 20)
		{
			return (1);
			ft_putstr("true");
		}
		ft_putstr("sharp");
	}
	return (0);
}*/

/* Проверяем, чтоб все сиввелы в мапе были корректными и состояти только из
 * '.' и '#' и чтобы в каждой поданной строчке было 4 символа и \n
 * i - индекс символа в одномерном массиве
 * count - количество # в тетроминошке*/

int		test_file(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while ((s[i] == '.' || s[i] == '#' || s[i] == '\n') &&
			count <= 4 && s[i])
	{
		if (i == 20)
			break ;
		if (((i + 1) % 5 == 0) && s[i] != '\n' && i != 0)
			return (0);
		if (s[i] == '#')
			count++;
		i++;
	}
	if (count == 4 && sharp_connection(s))
	{
		if (((s[i] == '\n' && s[i - 1] == '\n') || s[i] == '\0')
				&& count == 4 && i == 20)
			return (1);
	}
	return (0);
}

int		sharp_connection(char *str)
{
	int count;
	int i;

	//ft_putstr("count");
	count = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				count++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				count++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				count++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				count++;
		}
		i++;
	}
	ft_putnbr(count);
	return (count == 6 || count == 8);
}
