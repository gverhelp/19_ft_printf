/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:17:24 by gverhelp          #+#    #+#             */
/*   Updated: 2019/10/25 12:22:00 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					a;
	int					plusmoins;
	unsigned long int	rep;

	a = 0;
	rep = 0;
	plusmoins = 1;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			plusmoins *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		rep = rep * 10 + str[a] - 48;
		a++;
	}
	if (rep > 2147483648)
		return ((plusmoins == -1) ? 0 : -1);
	return (rep * plusmoins);
}
