/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:21:05 by selbouka          #+#    #+#             */
/*   Updated: 2025/01/10 10:45:28 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(va_list list, char format, int *count)
{
	if (format == '%')
		*count += write(1, &format, 1);
	else if (format == 'c')
		*count += ft_putchar(va_arg(list, int));
	else if (format == 's')
		*count += ft_putstr(va_arg(list, char *));
	else if (format == 'i' || format == 'd')
		ft_putnbr(va_arg(list, int), count);
	else if (format == 'u')
		ft_putunbr(va_arg(list, unsigned int), count);
	else if (format == 'x')
		ft_printhex(va_arg(list, unsigned int), 1, count);
	else if (format == 'X')
		ft_printhex(va_arg(list, unsigned int), 0, count);
	else if (format == 'p')
	{
		*count += write (1, "0x", 2);
		ft_adress(va_arg(list, void *), count);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		list;
	int			i;
	int			count;

	count = 0;
	va_start (list, format);
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (0);
			print(list, format[i], &count);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}
