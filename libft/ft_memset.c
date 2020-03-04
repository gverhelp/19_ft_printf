/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:59:47 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/28 10:12:44 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	a;

	a = 0;
	if (b == NULL)
		return (NULL);
	while (len > a)
	{
		((unsigned char*)b)[a] = (unsigned char)c;
		a++;
	}
	return (b);
}
