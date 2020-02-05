/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:20:24 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/04 16:15:02 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_utils1(t_list *list, int len, char *c)
{
	char	*tmp;
	char	*tmp2;

	while (list->nb > len)
	{
		tmp = list->str;
		if (!(tmp2 = ft_strdup(c)))
			return (0);
		if (!(list->str = ft_strjoin(tmp2, list->str)))
			return (0);
		free(tmp);
		free(tmp2);
		len++;
	}
	return (len);
}

int	ft_utils2(t_list *list, int len, char *c)
{
	char	*tmp;
	char	*tmp2;

	while (list->nb > len)
	{
		tmp = list->str;
		if (!(tmp2 = ft_strdup(c)))
			return (0);
		if (!(list->str = ft_strjoin(list->str, tmp2)))
			return (0);
		free(tmp);
		free(tmp2);
		len++;
	}
	return (len);
}

int	ft_utils3(t_list *list, int len, char *c)
{
	char	*tmp;
	char	*tmp2;

	while (list->nb2 > len)
	{
		tmp = list->str;
		if (!(tmp2 = ft_strdup(c)))
			return (0);
		if (!(list->str = ft_strjoin(tmp2, list->str)))
			return (0);
		free(tmp);
		free(tmp2);
		len++;
	}
	return (len);
}

int	ft_utils4(t_list *list, int len, char *c)
{
	char *tmp;
	char *tmp2;

	tmp = list->str;
	if (!(tmp2 = ft_strdup(c)))
		return (0);
	if (!(list->str = ft_strjoin(tmp2, list->str)))
		return (0);
	free(tmp);
	free(tmp2);
	len++;
	return (len);
}

int	ft_utils5(t_list *list, int len, char *c)
{
	char	*tmp;
	char	*tmp2;

	tmp = list->str;
	if (!(tmp2 = ft_strdup("-")))
		return (0);
	if (!(list->str = ft_strjoin(tmp2, list->str)))
		return (0);
	free(tmp);
	free(tmp2);
	return (len);
}
