/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseo <yoseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:12:45 by yoseo             #+#    #+#             */
/*   Updated: 2022/02/12 07:02:06 by yoseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	result;

	result = 0;
	if (str == 0)
		return (ft_print_str("(null)"));
	while (*str)
	{
		result += ft_print_char(*str);
		++str;
	}
	return (result);
}
