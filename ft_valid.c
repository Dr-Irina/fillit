/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 11:03:16 by wned              #+#    #+#             */
/*   Updated: 2019/01/31 17:13:35 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Тетромино правильной формы, все '#' касаются друг друга
*/

int			sharp_connection(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (i <= 19)
	{
		if (str[i] == '#')
		{
			if (i - 1 >= 0 && str[i - 1] == '#')
				count++;
			if (i + 1 <= 19 && str[i + 1] == '#')
				count++;
			if (i + 5 <= 19 && str[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && str[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 8 || count == 6)
		return (1);
	return (0);
}

/*
** Проверяем, чтоб было только 4 '#' и правильное поле 4х4
*/

int			is_blockvalid(char *str)
{
	int		i;
	int		hash;

	i = 0;
	hash = 0;
	while ((str[i] == '.' || str[i] == '#' || str[i] == '\n') &&
			hash < 5 && str[i])
	{
		if (i == 20)
			break ;
		if ((i + 1 % 5 == 0) && str[i] != '\n' && i != 0)
			return (0);
		if (str[i] == '#')
			hash++;
		i++;
	}
	if (hash == 4 && sharp_connection(str))
	{
		if (((str[i] == '\n' && str[i - 1] == '\n') || str[i] == '\0')
				&& hash == 4 && i == 20)
			return (1);
	}
	return (0);
}

/*
** Проверяем, чтоб было подано максимум 26 тетроминок
*/

int			is_filevalid(char *str)
{
	int		i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (i >= 546)
			return (0);
		if (is_blockvalid(&str[i]) == 0)
			return (0);
		i += 19;
		if (str[i + 1] && str[i + 2] == '\0')
			return (0);
		if (str[i + 1] == '\n')
			i += 2;
		else
			break ;
	}
	return (1);
}

char		*read_file(int fd)
{
	char	*str;
	char	*buffer;
	int		fr;

	buffer = ft_strnew(20);
	if ((fd < 0 || read(fd, buffer, 0) < 0))
		return (NULL);
	str = (char*)ft_memalloc(sizeof(char));
	while ((fr = read(fd, buffer, 20)))
	{
		buffer[fr] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strlen(str) > 570)
			return (NULL);
	}
	ft_memdel((void**)&buffer);
	str = ft_strjoin(str, "\0");
	return (str);
}
