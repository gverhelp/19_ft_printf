/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:41:09 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/28 10:54:29 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	count;

	a = 0;
	b = 0;
	count = 0;
	while (dst[a] != '\0' && a < size)
		a++;
	count += a;
	while (src[b] != '\0')
		b++;
	count += b;
	if (a == size)
		return (count);
	b = 0;
	while (src[b] != '\0' && a + b < size - 1)
	{
		dst[a + b] = src[b];
		b++;
	}
	dst[a + b] = '\0';
	return (count);
}
