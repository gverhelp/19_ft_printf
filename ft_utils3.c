/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:45:09 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/04 12:56:08 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_utils11(t_list2 *list2, const char *format, t_list *list)
{
	if (format[list2->a] == '.')
	{
		list->point = 1;
		list2->compt += 1;
		list2->a += 1;
	}
	if (format[list2->a] == '0')
	{
		list->zero2 = 1;
		list2->compt += 1;
		list2->a += 1;
	}
}

void	ft_utils12(t_list2 *list2, const char *format, t_list *list)
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
			list->star2 = 1;
			list2->compt += 1;
			list2->a += 1;
		}
		while (ft_isdigit(format[list2->a]) == 1)
		{
			list->nb2 = list->nb2 * 10 + format[list2->a] - '0';
			list2->compt += 1;
			list2->a += 1;
		}
	}
}

void	ft_init_list3(t_list3 *list3)
{
	list3->a = 0;
	list3->size = 0;
}
