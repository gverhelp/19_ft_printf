/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:48:51 by gverhelp          #+#    #+#             */
/*   Updated: 2020/01/14 14:33:47 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*s;

	a = 0;
	if (s1 == NULL)
		return (NULL);
	if (!(s = malloc((ft_strlen(s1) + 1) * sizeof(*s))))
		return (NULL);
	while (s1[a] != '\0')
	{
		s[a] = s1[a];
		a++;
	}
	s[a] = '\0';
	return (s);
}
