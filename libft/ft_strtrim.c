/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:15:47 by hrice             #+#    #+#             */
/*   Updated: 2018/11/30 20:08:40 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	char	*fresh;
	char	*nl;

	if (!s)
		return (NULL);
	k = ft_strlen(s);
	i = 0;
	while (s[k - 1] == '\n' || s[k - 1] == '\t' || s[k - 1] == ' ')
		k--;
	while ((s[i] == '\n' || s[i] == '\t' || s[i] == ' ') && k != i)
	{
		i++;
		k--;
	}
	if (!(fresh = ft_strnew(k)))
		return (NULL);
	nl = fresh;
	while (k-- && s[i])
	{
		*fresh = s[i++];
		fresh++;
	}
	return (nl);
}
