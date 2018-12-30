/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:54:37 by hrice             #+#    #+#             */
/*   Updated: 2018/11/26 20:00:39 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dst = (char *)malloc(sizeof(*dst) * i + 1);
	if (dst)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			dst[i] = s1[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
		return (NULL);
	return (dst);
}
