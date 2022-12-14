/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gskrasti <gskrasti@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:20:14 by gskrasti          #+#    #+#             */
/*   Updated: 2022/07/31 16:13:34 by gskrasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

int		ft_printf(const char *str, ...);
char	*ft_uitoa(unsigned int n);
int		ft_hex_low(unsigned int n);
int		ft_hex_upper(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_putptr(void	*ptr);

#endif