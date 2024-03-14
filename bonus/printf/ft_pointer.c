/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:06:38 by moer-ret          #+#    #+#             */
/*   Updated: 2023/12/01 00:00:35 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_hex(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb < 16)
	{
		if (nb <= 9)
			count += ft_putchar(nb + '0');
		else
			count += ft_putchar(nb - 10 + 'a');
	}
	else if (nb >= 16)
	{
		count += ft_hex(nb / 16);
		count += ft_hex(nb % 16);
	}
	return (count);
}

int	ft_pointer(unsigned long nb)
{
	int	count;

	count = 0;
	if (!nb)
		return (ft_putstr("0x0"));
	else
	{
		count += ft_putstr("0x");
		count += ft_hex(nb);
	}
	return (count);
}
