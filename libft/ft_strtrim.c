/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:43:35 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/29 10:51:24 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set)
{
	int	a;

	a = 0;
	while (set[a] != '\0')
	{
		if (set[a] == c)
		{
			return (1);
		}
		a++;
	}
	return (0);
}

static int	ft_trimdebut(char const *s1, char const *set)
{
	int	a;
	int	suppdebut;

	a = 0;
	suppdebut = 0;
	while (s1[a] != '\0')
	{
		if (ft_check(s1[a], set) == 1)
		{
			suppdebut++;
			a++;
		}
		else
			return (suppdebut);
	}
	return (suppdebut);
}

static int	ft_trimfin(char const *s1, char const *set)
{
	int	a;
	int	b;
	int suppfin;

	b = 0;
	while (s1[b] != '\0')
		b++;
	a = b - 1;
	suppfin = 0;
	while (a > 0)
	{
		if (ft_check(s1[a], set) == 1)
		{
			suppfin++;
			a--;
		}
		else
			return (suppfin);
	}
	return (suppfin);
}

static char	*ft_sizeneg(void)
{
	char	*str;

	str = malloc((1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		debut;
	int		size;
	char	*str;

	a = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	debut = ft_trimdebut(s1, set);
	size = ft_strlen(s1) - debut - ft_trimfin(s1, set);
	if (size < 0)
		return (ft_sizeneg());
	if (!(str = malloc((size + 1) * sizeof(*str))))
		return (NULL);
	while (size > 0)
	{
		str[a] = s1[debut];
		a++;
		debut++;
		size--;
	}
	str[a] = '\0';
	return (str);
}
