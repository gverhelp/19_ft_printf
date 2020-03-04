/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:17:40 by gverhelp          #+#    #+#             */
/*   Updated: 2020/01/20 13:18:17 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	if (!(s = malloc((len + 1) * sizeof(*s))))
		return (NULL);
	if (n == 0)
		s[len - 1] = 0 + '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len] = '\0';
	while (n > 0)
	{
		len--;
		s[len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
