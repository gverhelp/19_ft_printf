/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:09:19 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/04 15:54:17 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_list(t_list *list)
{
	list->zero = 0;
	list->zero2 = 0;
	list->tiret = 0;
	list->point = 0;
	list->star = 0;
	list->star2 = 0;
	list->nb = 0;
	list->nb2 = 0;
	list->str = 0;
	list->flag = 0;
	list->flag2 = 0;
}

void	ft_init_list2(t_list2 *list2, int b)
{
	list2->a = b;
	list2->compt = 0;
}

int		ft_checkflag(int a, const char *format, t_list *list)
{
	t_list2	list2;

	a++;
	ft_init_list2(&list2, a);
	if (format[list2.a] == '0')
	{
		list->zero = 1;
		list2.compt += 1;
		list2.a += 1;
	}
	ft_utils10(&list2, format, list);
	ft_utils11(&list2, format, list);
	ft_utils12(&list2, format, list);
	return (list2.compt);
}

int		ft_converter(int a, const char *format, va_list ap, t_list list)
{
	if (format[a] == 'c')
		return (ft_convert_c(ap, list));
	if (format[a] == 's')
		return (ft_convert_s(ap, list));
	if (format[a] == 'p')
		return (ft_convert_p(ap, list));
	if (format[a] == 'd' || format[a] == 'i')
		return (ft_convert_d_i(ap, list));
	if (format[a] == 'u')
		return (ft_convert_u(ap, list));
	if (format[a] == 'x' || format[a] == 'X')
		return (ft_convert_x(ap, list, format, a));
	if (format[a] == '%')
		return (ft_convert_percent(ap, list));
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	list;
	t_list3 list3;

	ft_init_list3(&list3);
	va_start(ap, format);
	while (format[list3.a] != '\0')
	{
		ft_init_list(&list);
		if (format[list3.a] != '%')
			list3.size = ft_utils9(format, list3.a, list3.size);
		if (format[list3.a] == '%')
		{
			list3.a = list3.a + ft_checkflag(list3.a, format, &list) + 1;
			if (format[list3.a] == '\0')
			{
				ft_utils8(&list);
				return (0);
			}
			list3.size += ft_converter(list3.a, format, ap, list);
		}
		list3.a++;
	}
	va_end(ap);
	return (list3.size);
}
