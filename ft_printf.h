/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:16:42 by gverhelp          #+#    #+#             */
/*   Updated: 2020/02/04 13:01:53 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_list
{
	int		zero;
	int		zero2;
	int		tiret;
	int		point;
	int		star;
	int		star2;
	int		nb;
	int		nb2;
	int		flag;
	int		flag2;
	char	*str;
}				t_list;

typedef struct	s_list2
{
	int	a;
	int	compt;
}				t_list2;

typedef struct	s_list3
{
	int	a;
	int	size;
}				t_list3;

int				ft_printf(const char *format, ...);
int				ft_checkflag(int a, const char *format, t_list *list);
int				ft_converter(int a, const char *format, va_list ap,
		t_list list);
int				ft_convert_c(va_list ap, t_list list);
int				ft_convert_s(va_list ap, t_list list);
int				ft_convert_p(va_list ap, t_list list);
int				ft_convert_d_i(va_list ap, t_list list);
int				ft_convert_u(va_list ap, t_list list);
int				ft_convert_percent(va_list ap, t_list list);
int				ft_convert_x(va_list ap, t_list list, const char *format,
		int a);
int				ft_utils1(t_list *list, int len, char *c);
int				ft_utils2(t_list *list, int len, char *c);
int				ft_utils3(t_list *list, int len, char *c);
int				ft_utils4(t_list *list, int len, char *c);
int				ft_utils5(t_list *list, int len, char *c);
int				ft_utils6(t_list *list, int len);
int				ft_utils7(t_list *list, int len);
void			ft_utils8(t_list *list);
int				ft_utils9(const char *format, int a, int size);
void			ft_utils10(t_list2 *list2, const char *format, t_list *list);
void			ft_utils11(t_list2 *list2, const char *format, t_list *list);
void			ft_utils12(t_list2 *list2, const char *format, t_list *list);
void			ft_init_list(t_list *list);
void			ft_init_list2(t_list2 *list2, int b);
void			ft_init_list3(t_list3 *list3);

#endif
