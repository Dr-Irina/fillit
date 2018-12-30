/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:15:13 by hrice             #+#    #+#             */
/*   Updated: 2018/11/30 18:12:04 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*fresh;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (!fresh)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
