/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:39:11 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/28 16:13:23 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long int	a;

	a = 0;
	if (dst == NULL)
		return (NULL);
	while (a < n)
	{
		((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
		a++;
	}
	return (dst);
}
