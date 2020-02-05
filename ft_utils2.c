/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:19:45 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/04 12:44:50 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_utils6(t_list *list, int len)
{
	char *tmp;

	tmp = list->str;
	if (!(list->str = ft_substr(list->str, 1, len)))
		return (0);
	free(tmp);
	len = ft_strlen(list->str);
	list->flag = 1;
	len++;
	return (len);
}

int		ft_utils7(t_list *list, int len)
{
	char	*tmp;

	tmp = list->str;
	if (!(list->str = ft_substr(list->str, 1, len)))
		return (0);
	free(tmp);
	len = ft_strlen(list->str);
	list->flag = 1;
	if (list->star2 == 1 && list->flag2 == 1)
		len++;
	return (len);
}

void	ft_utils8(t_list *list)
{
	list->str = ft_strdup("");
	ft_putstr(list->str);
	free(list->str);
}

int		ft_utils9(const char *format, int a, int size)
{
	ft_putchar(format[a]);
	size++;
	return (size);
}

void	ft_utils10(t_list2 *list2, const char *format, t_list *list)
{
	while (ft_isdigit(format[list2->a]) == 1 || format[list2->a] == '-' ||
			format[list2->a] == '*')
	{
		if (format[list2->a] == '-')
		{
			list->tiret = 1;
			list2->compt += 1;
			list2->a += 1;
		}
		if (format[list2->a] == '*')
		{
			list->star = 1;
			list2->compt += 1;
			list2->a += 1;
		}
		while (ft_isdigit(format[list2->a]) == 1)
		{
			list->nb = list->nb * 10 + format[list2->a] - '0';
			list2->compt += 1;
			list2->a += 1;
		}
	}
}
