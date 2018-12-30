/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:43:13 by hrice             #+#    #+#             */
/*   Updated: 2018/11/29 21:42:36 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	while (i < len && (char)s[i] != (char)c)
		i++;
	if ((char)s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
