/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:34:15 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/29 10:40:41 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*str;

	a = 0;
	str = (unsigned char*)s;
	while (a < n)
	{
		if (str[a] == (unsigned char)c)
			return (&str[a]);
		a++;
	}
	return (NULL);
}
