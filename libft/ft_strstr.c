/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:53:33 by hrice             #+#    #+#             */
/*   Updated: 2018/11/29 18:37:32 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		while (haystack[i] == needle[i])
		{
			if (!needle[i + 1])
				return ((char *)haystack);
			i++;
		}
		i = 0;
		haystack++;
	}
	return (0);
}
