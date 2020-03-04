/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:15:26 by gverhelp          #+#    #+#             */
/*   Updated: 2019/12/17 18:15:08 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_utoa(unsigned int n)
{
	unsigned int	len;
	char			*s;

	len = ft_intlen(n);
	if (!(s = malloc((len + 1) * sizeof(*s))))
		return (NULL);
	if (n == 0)
		s[len - 1] = 0 + '0';
	s[len] = '\0';
	while (n > 0)
	{
		len--;
		s[len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
