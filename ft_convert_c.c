/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:19:26 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/04 13:41:12 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_norme_c1(va_list ap, t_list *list)
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
}

static int	ft_norme_c2(t_list *list, int len)
{
	if (list->str[0] == 0)
	{
		if (list->nb == 0)
		{
			write(1, "\0", 1);
			list->flag = 1;
		}
		else
			len++;
	}
	return (len);
}

static int	ft_norme_c3(t_list *list, int len)
{
	if (list->tiret == 0)
	{
		while (list->nb > len)
		{
			write(1, " ", 1);
			len++;
		}
	}
	write(1, list->str, 1);
	if (list->tiret == 1)
	{
		while (list->nb > len)
		{
			write(1, " ", 1);
			len++;
		}
	}
	return (len);
}

int			ft_convert_c(va_list ap, t_list list)
{
	int		len;
	int		flag;

	flag = 0;
	ft_norme_c1(ap, &list);
	if (!(list.str = ft_chrdup(va_arg(ap, int))))
		return (0);
	len = ft_strlen(list.str);
	len = ft_norme_c2(&list, len);
	if (list.nb != 0)
		len = ft_norme_c3(&list, len);
	else
		ft_putstr(list.str);
	free(list.str);
	if (list.flag == 1)
		return (len + 1);
	return (len);
}
