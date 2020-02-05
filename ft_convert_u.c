/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:22:17 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/03 15:01:12 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_norme_u1(va_list ap, t_list *list)
{
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
	{
		list->nb2 = va_arg(ap, int);
		if (list->nb2 < 0)
		{
			if (list->tiret == 0)
				list->nb2 = list->nb;
		}
	}
}

static int	ft_norme_u2(t_list *list, int len)
{
	if (list->nb != 0)
	{
		if (list->tiret == 0)
		{
			if (list->zero == 0)
				len = ft_utils1(list, len, " ");
			if (list->zero == 1)
				len = ft_utils1(list, len, "0");
		}
		if (list->tiret == 1)
			len = ft_utils2(list, len, " ");
	}
	return (len);
}

static int	ft_norme_u3(t_list *list, int len)
{
	if (list->str[0] == 0 && list->nb2 == 0)
		len--;
	len = ft_utils3(list, len, "0");
	if (list->nb != 0)
	{
		len = ft_strlen(list->str);
		if (list->tiret == 0)
			len = ft_utils1(list, len, " ");
		if (list->tiret == 1)
			len = ft_utils2(list, len, " ");
	}
	return (len);
}

int			ft_convert_u(va_list ap, t_list list)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	ft_norme_u1(ap, &list);
	if (!(tmp2 = ft_utoa(va_arg(ap, int))))
		return (0);
	if (!(list.str = ft_strdup(tmp2)))
		return (0);
	free(tmp2);
	len = ft_strlen(list.str);
	if (list.str[0] == '0' && list.point == 1 && list.nb2 == 0)
	{
		tmp = list.str;
		if (!(list.str = ft_strdup("")))
			return (0);
		free(tmp);
	}
	if (list.point == 0)
		len = ft_norme_u2(&list, len);
	if (list.point == 1)
		len = ft_norme_u3(&list, len);
	ft_putstr(list.str);
	free(list.str);
	return (len);
}
