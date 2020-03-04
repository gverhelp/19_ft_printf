/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:36:11 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/23 14:44:56 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	char	*str;

	a = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = ft_strdup(s);
	if (str == NULL)
		return (0);
	while (str[a] != '\0')
	{
		str[a] = (*f)(a, s[a]);
		a++;
	}
	return (str);
}
