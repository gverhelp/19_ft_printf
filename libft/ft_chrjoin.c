/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:35:45 by gverhelp          #+#    #+#             */
/*   Updated: 2019/12/18 11:36:00 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrjoin(char const *s1, char const c)
{
	int		size;
	int		a;
	char	*str;

	a = 0;
	if (s1 == NULL)
		return (NULL);
	size = ft_strlen((char*)s1) + 1;
	str = malloc((size + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		str[a] = s1[a];
		a++;
	}
	str[a] = c;
	str[a + 1] = '\0';
	return (str);
}
