/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:33:51 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/28 16:23:37 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (src[a] != '\0')
		a++;
	if (size == 0)
		return (a);
	while (b + 1 < size && src[b] != '\0')
	{
		dst[b] = src[b];
		b++;
	}
	dst[b] = '\0';
	return (a);
}
