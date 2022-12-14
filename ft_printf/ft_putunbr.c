/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gskrasti <gskrasti@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:45:27 by gskrasti          #+#    #+#             */
/*   Updated: 2022/07/30 14:45:27 by gskrasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	char	*str;
	int		i;
	int		len;

	str = ft_uitoa(n);
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	free (str);
	return (i);
}
