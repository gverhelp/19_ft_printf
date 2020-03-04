/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:36:44 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/24 13:39:39 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	a;
	char	*s;

	a = 0;
	if (count == 0 && size == 0)
	{
		count = 1;
		size = 1;
	}
	s = malloc((count) * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
