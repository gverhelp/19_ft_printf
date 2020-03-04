/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:07:00 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/29 10:49:59 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	char	*str;
	char	*to_find;

	a = 0;
	str = (char*)haystack;
	to_find = (char*)needle;
	if (to_find[a] == '\0')
		return (str);
	while (str[a] != '\0' && len > a)
	{
		b = 0;
		while (str[a + b] == to_find[b] && len > (a + b))
		{
			b++;
			if (to_find[b] == '\0')
				return (&str[a]);
		}
		a++;
	}
	return (0);
}
