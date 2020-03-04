/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:53:49 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/28 10:59:39 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] != '\0' && n > a &&
			(unsigned char)s1[a] == (unsigned char)s2[a])
		a++;
	if (n == a)
		return (0);
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
