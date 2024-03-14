/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:59:52 by moer-ret          #+#    #+#             */
/*   Updated: 2023/11/30 22:44:46 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, const char format)
{
	int	count;

	count = 0;
	if (nb < 16)
	{
		if (nb <= 9)
			count += ft_putchar(nb + '0');
		else
		{
			if (format == 'x')
				count += ft_putchar(nb - 10 + 'a');
			else if (format == 'X')
				count += ft_putchar(nb - 10 + 'A');
		}
	}
	else if (nb >= 16)
	{
		count += ft_puthex(nb / 16, format);
		count += ft_puthex(nb % 16, format);
	}
	return (count);
}
