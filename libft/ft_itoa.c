/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:43:21 by hrice             #+#    #+#             */
/*   Updated: 2018/11/30 19:29:21 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		len;
	int		temp;
	char	*str;

	len = (n < 0) ? 2 : 1;
	temp = n;
	while (temp /= 10)
		len++;
	temp = n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (--len != ((n < 0) - 1))
	{
		str[len] = (n < 0) ? '0' - (n % 10) : '0' + (n % 10);
		n = n / 10;
	}
	if (temp < 0)
		str[0] = '-';
	return (str);
}
