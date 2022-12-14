/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gskrasti <gskrasti@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:06:41 by gskrasti          #+#    #+#             */
/*   Updated: 2022/07/26 15:06:41 by gskrasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print(char *hex, int i);

int	ft_hex_low(unsigned int n)
{
	int		remainder;
	char	*hex;
	int		i;
	int		length;

	remainder = 0;
	i = 0;
	length = 0;
	hex = malloc(12 * sizeof(char));
	while (n >= 16)
	{
		remainder = n % 16;
		n /= 16;
		if (remainder >= 10)
			hex[i++] = remainder + '0' + 39;
		else
			hex[i++] = remainder + '0';
	}
	if (n >= 10)
		hex[i] = n + '0' + 39;
	else
		hex[i] = n + '0';
	length = print(hex, i);
	return (length);
}

int	ft_hex_upper(unsigned int n)
{
	int		remainder;
	char	*hex;
	int		i;
	int		length;

	remainder = 0;
	i = 0;
	length = 0;
	hex = malloc(12 * sizeof(char));
	while (n >= 16)
	{
		remainder = n % 16;
		n /= 16;
		if (remainder >= 10)
			hex[i++] = remainder + '0' + 7;
		else
			hex[i++] = remainder + '0';
	}
	if (n >= 10)
		hex[i] = n + '0' + 7;
	else
		hex[i] = n + '0';
	length = print(hex, i);
	return (length);
}

static int	print(char *hex, int i)
{
	int	length;

	length = 0;
	while (i >= 0)
	{
		ft_putchar_fd(hex[i--], 1);
		length++;
	}
	free (hex);
	return (length);
}
