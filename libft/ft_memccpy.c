/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:45:30 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/28 16:11:02 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
		if (((unsigned char*)src)[a] == (unsigned char)c)
			return (&dst[a] + 1);
		a++;
	}
	return (NULL);
}
