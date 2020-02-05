/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:18:31 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/05 12:01:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_norme_s1(va_list ap, t_list *list)
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
		list->nb2 = va_arg(ap, int);
}

static int	ft_norme_s2(t_list *list, int len)
{
	if (list->nb != 0)
	{
		if (list->tiret == 0)
			len = ft_utils1(list, len, " ");
		if (list->tiret == 1)
			len = ft_utils2(list, len, " ");
	}
	return (len);
}

static int	ft_norme_s3(t_list *list, int len)
{
	char	*tmp;

	tmp = list->str;
	if (!(list->str = ft_substr(list->str, 0, list->nb2)))
		return (0);
	free(tmp);
	len = ft_strlen(list->str);
	if (list->nb >= list->nb2)
	{
		if (list->tiret == 1)
			len = ft_utils2(list, len, " ");
		if (list->tiret == 0)
			len = ft_utils1(list, len, " ");
	}
	if (list->nb < list->nb2)
	{
		if (list->tiret == 1)
			len = ft_utils2(list, len, " ");
		if (list->tiret == 0)
			len = ft_utils1(list, len, " ");
	}
	return (len);
}

int			ft_convert_s(va_list ap, t_list list)
{
	int		len;
	char	*tmp;

	ft_norme_s1(ap, &list);
	if (!(list.str = ft_strdup(va_arg(ap, char*))))
	{
		tmp = list.str;
		if (!(list.str = ft_strdup("(null)")))
			return (0);
		free(tmp);
	}
	len = ft_strlen(list.str);
	if (list.point == 0)
		len = ft_norme_s2(&list, len);
	if (list.point == 1)
		len = ft_norme_s3(&list, len);
	ft_putstr(list.str);
	free(list.str);
	return (len);
}
