/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:21:21 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/03 14:01:40 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_norme_percent1(va_list ap, t_list *list)
{
	int	len;

	if (!(list->str = ft_strdup("%")))
		return (0);
	len = ft_strlen(list->str);
	if (list->star == 1)
	{
		list->nb = va_arg(ap, int);
		if (list->nb < 0)
		{
			list->tiret = 1;
			list->nb *= -1;
		}
	}
	if (list->star2 == 1)
		list->nb2 = va_arg(ap, int);
	return (len);
}

int			ft_convert_percent(va_list ap, t_list list)
{
	int		len;

	len = ft_norme_percent1(ap, &list);
	if (list.zero == 0)
	{
		if (list.tiret == 0)
			len = ft_utils1(&list, len, " ");
		if (list.tiret == 1)
			len = ft_utils2(&list, len, " ");
	}
	if (list.zero == 1)
	{
		if (list.tiret == 0)
			len = ft_utils1(&list, len, "0");
		if (list.tiret == 1)
			len = ft_utils2(&list, len, " ");
	}
	ft_putstr(list.str);
	free(list.str);
	return (len);
}
