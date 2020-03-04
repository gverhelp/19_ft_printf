/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:20:21 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/28 16:16:39 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;

	if (dst == 0 && src == 0)
		return (0);
	if (src < dst)
	{
		a = len;
		while (0 < a)
		{
			a--;
			((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
		}
	}
	else
	{
		a = 0;
		while (a < len)
		{
			((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
			a++;
		}
	}
	return (dst);
}
