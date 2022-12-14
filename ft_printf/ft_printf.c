/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gskrasti <gskrasti@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:53:19 by gskrasti          #+#    #+#             */
/*   Updated: 2022/07/31 15:40:25 by gskrasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char c, va_list lst);

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_check(str[++i], lst);
			i++;
		}
		else
		{
			length += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(lst);
	return (length);
}

static int	ft_check(char c, va_list lst)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = ft_putchar(va_arg(lst, unsigned int));
	if (c == 's')
		length = ft_putstr(va_arg(lst, char *));
	if (c == 'p')
		length = ft_putptr(va_arg(lst, void *));
	if (c == 'i' || c == 'd')
		length = ft_putnbr(va_arg(lst, int));
	if (c == 'u')
		length = ft_putunbr(va_arg(lst, unsigned int));
	if (c == 'x')
		length = ft_hex_low(va_arg(lst, int));
	if (c == 'X')
		length = ft_hex_upper(va_arg(lst, int));
	if (c == '%')
		length = ft_putchar('%');
	return (length);
}
