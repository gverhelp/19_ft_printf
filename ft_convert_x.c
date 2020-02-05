/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:22:50 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/03 15:09:09 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_norme_x1(va_list ap, t_list *list)
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

static int	ft_norme_x2(va_list ap, t_list *list, const char *format, int a)
{
	int		len;
	char	*tmp2;

	if (format[a] == 'x')
	{
		if (!(tmp2 = ft_utoa_base(va_arg(ap, unsigned int), 16, 1)))
			return (0);
		if (!(list->str = ft_strdup(tmp2)))
			return (0);
		free(tmp2);
	}
	if (format[a] == 'X')
	{
		if (!(tmp2 = ft_utoa_base(va_arg(ap, unsigned int), 16, 2)))
			return (0);
		if (!(list->str = ft_strdup(tmp2)))
			return (0);
		free(tmp2);
	}
	len = ft_strlen(list->str);
	return (len);
}

static int	ft_norme_x3(t_list *list, int len)
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

static int	ft_norme_x4(t_list *list, int len)
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

int			ft_convert_x(va_list ap, t_list list, const char *format, int a)
{
	int		len;
	char	*str;
	char	*tmp;

	ft_norme_x1(ap, &list);
	len = ft_norme_x2(ap, &list, format, a);
	if (list.str[0] == '0' && list.point == 1 && list.nb2 == 0)
	{
		tmp = list.str;
		if (!(list.str = ft_strdup("")))
			return (0);
		free(tmp);
	}
	if (list.point == 0)
		len = ft_norme_x3(&list, len);
	if (list.point == 1)
		len = ft_norme_x4(&list, len);
	ft_putstr(list.str);
	free(list.str);
	return (len);
}
