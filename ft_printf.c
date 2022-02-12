/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseo <yoseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 02:59:14 by yoseo             #+#    #+#             */
/*   Updated: 2022/02/12 09:18:12 by yoseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(const char **format, va_list *ap)
{
	const char	*s;
	int			result;

	result = 0;
	s = *format;
	++s;
	if (*s == 'c')
		result = ft_print_char(va_arg(*ap, int));
	else if (*s == 's')
		result = ft_print_str(va_arg(*ap, char *));
	else if (*s == '%')
		result = ft_print_char('%');
	else if (*s == 'd' || *s == 'i' || *s == 'u'
		|| *s == 'x' || *s == 'X' || *s == 'p')
		result = ft_print_num(ap, *s);
	*format = s;
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int			result;
	va_list		ap;
	const char	*str;

	result = 0;
	str = format;
	va_start(ap, format);
	while (*str)
	{
		if (*str == '%')
			result += ft_print_format(&str, &ap);
		else
			result += ft_print_char(*str);
		if (*str == 0)
			break ;
		++str;
	}
	va_end(ap);
	return (result);
}
