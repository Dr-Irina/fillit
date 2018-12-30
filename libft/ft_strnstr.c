/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:44:12 by hrice             #+#    #+#             */
/*   Updated: 2018/12/03 13:56:25 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		while (haystack[i] == needle[i] && (len - i))
		{
			if (needle[i + 1] == '\0')
				return ((char *)haystack);
			i++;
		}
		i = 0;
		haystack++;
		len--;
	}
	return (NULL);
}
