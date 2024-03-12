/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 05:26:05 by moer-ret          #+#    #+#             */
/*   Updated: 2023/12/02 04:25:52 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	check(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (format[i + 1] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (format[i + 1] == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format[i + 1] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		count += ft_puthex(va_arg(args, unsigned int), format[i + 1]);
	else if (format [i + 1] == 'p')
		count += ft_pointer (va_arg(args, unsigned long));
	else if (format[i + 1] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		else if (format[i] == '%')
		{
			count += check(&format[i], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	int b = printf("%d\n", INT_MIN);
//  	int a = ft_printf("%d\n", INT_MIN);
// 	printf("%d %d", a, b);
// }
