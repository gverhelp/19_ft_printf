/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:20:01 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/05 11:59:43 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_norme_d_i1(va_list ap, t_list *list)
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
			{
				list->nb2 = list->nb;
				list->flag2 = 1;
			}
		}
	}
}

static int	ft_norme_d_i2(t_list *list, int len)
{
	if (list->nb != 0)
	{
		if (list->tiret == 0)
		{
			if (list->zero == 0)
				len = ft_utils1(list, len, " ");
			if (list->zero == 1)
			{
				if (list->str[0] == '-')
					len = ft_utils6(list, len);
				len = ft_utils1(list, len, "0");
				if (list->flag == 1)
					len = ft_utils5(list, len, "-");
			}
		}
		if (list->tiret == 1)
			len = ft_utils2(list, len, " ");
	}
	return (len);
}

static int	ft_norme_d_i3(t_list *list, int len)
{
	if (list->str[0] == 0 && list->nb2 == 0)
		len--;
	if (list->str[0] == '-')
		len = ft_utils7(list, len);
	len = ft_utils3(list, len, "0");
	if (list->nb != 0)
	{
		len = ft_strlen(list->str);
		if (list->flag == 1)
			len = ft_utils4(list, len, "-");
		if (list->tiret == 0)
			len = ft_utils1(list, len, " ");
		if (list->tiret == 1)
			len = ft_utils2(list, len, " ");
	}
	if (list->nb == 0 && list->flag == 1)
		len = ft_utils4(list, len, "-");
	return (len);
}

int			ft_convert_d_i(va_list ap, t_list list)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	ft_norme_d_i1(ap, &list);
	if (!(tmp2 = ft_itoa(va_arg(ap, int))))
		return (0);
	if (!(list.str = ft_strdup(tmp2)))
		return (0);
	free(tmp2);
	len = ft_strlen(list.str);
	if (list.str[0] == '0' && list.point == 1 && list.nb2 == 0 &&
			list.flag2 == 0)
	{
		tmp = list.str;
		list.str = ft_strdup("");
		free(tmp);
	}
	if (list.point == 0)
		len = ft_norme_d_i2(&list, len);
	if (list.point == 1)
		len = ft_norme_d_i3(&list, len);
	ft_putstr(list.str);
	free(list.str);
	return (len);
}
