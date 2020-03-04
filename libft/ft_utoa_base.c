/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:13:54 by gverhelp          #+#    #+#             */
/*   Updated: 2020/01/20 13:32:39 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(size_t n, size_t base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*ft_utoa_base(size_t n, size_t base, int whatsbase)
{
	int			len;
	char		*s;
	char		*rep;

	if (whatsbase == 1)
		rep = "0123456789abcdef";
	else
		rep = "0123456789ABCDEF";
	len = ft_intlen(n, base);
	if (!(s = malloc((len + 1) * sizeof(*s))))
		return (NULL);
	if (n == 0)
		s[len - 1] = 0 + '0';
	s[len] = '\0';
	while (n > 0)
	{
		len--;
		s[len] = rep[n % base];
		n /= base;
	}
	return (s);
}
