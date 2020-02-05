/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:20:37 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/04 11:55:13 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_norme_p1(va_list ap, t_list *list)
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

static int	ft_norme_p2(t_list *list, int len)
{
	char	*tmp;

	tmp = list->str;
	if (!(list->str = ft_strdup("0x")))
		return (0);
	len--;
	free(tmp);
	return (len);
}

static int	ft_norme_p3(t_list *list, int len)
{
	if (list->tiret == 0)
		len = ft_utils1(list, len, " ");
	if (list->tiret == 1)
		len = ft_utils2(list, len, " ");
	return (len);
}

int			ft_convert_p(va_list ap, t_list list)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	ft_norme_p1(ap, &list);
	if (!(tmp2 = ft_strdup("0x")))
		return (0);
	if (!(tmp = ft_utoa_base(va_arg(ap, size_t), 16, 1)))
		return (0);
	if (!(list.str = ft_strjoin(tmp2, tmp)))
		return (0);
	free(tmp);
	free(tmp2);
	len = ft_strlen(list.str);
	if (list.str[0] == '0' && list.point == 1 && list.nb2 == 0)
		len = ft_norme_p2(&list, len);
	if (list.nb != 0)
		len = ft_norme_p3(&list, len);
	ft_putstr(list.str);
	free(list.str);
	return (len);
}
