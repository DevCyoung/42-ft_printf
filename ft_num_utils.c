/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseo <yoseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:58:17 by yoseo             #+#    #+#             */
/*   Updated: 2022/02/12 09:19:20 by yoseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ull(unsigned long long num, char c, int bl, int is_plus)
{
	char	array[33];
	char	*temp;
	char	*str;
	int		result;

	str = "0123456789abcdef0123456789ABCDEF";
	array[32] = 0;
	temp = &array[31];
	result = 0;
	if (c == 'X')
		str += 16;
	while (1)
	{
		*temp = str[num % bl];
		num /= bl;
		if (num == 0)
			break ;
		--temp;
	}
	if (is_plus == -1)
		result += ft_print_str("-");
	if (c == 'p')
		result += ft_print_str("0x");
	result += ft_print_str(temp);
	return (result);
}

int	ft_print_num(va_list *ap, char c)
{
	unsigned long long	num;
	int					is_plus;
	int					bl;

	is_plus = 1;
	bl = 10;
	if (c == 'x' || c == 'X' || c == 'p')
		bl = 16;
	if (c == 'u')
		num = va_arg(*ap, unsigned int);
	else if (c == 'd' || c == 'i')
	{
		num = va_arg(*ap, int);
		if ((int)num < 0)
			is_plus = -1;
		if ((int)num == -2147483648)
			num = 2147483648;
		else
			num = (int)num * is_plus;
	}
	else if (c == 'x' || c == 'X')
		num = va_arg(*ap, unsigned int);
	else
		num = va_arg(*ap, unsigned long long);
	return (ft_print_ull(num, c, bl, is_plus));
}
