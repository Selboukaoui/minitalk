/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:45:59 by selbouka          #+#    #+#             */
/*   Updated: 2024/11/23 15:46:33 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned int n, int x, int *len)
{
	char	*forme;

	if (x == 1)
		forme = "0123456789abcdef";
	else if (x == 0)
		forme = "0123456789ABCDEF";
	if (n < 0)
	{
		*len += write(1, "-", 1);
		n *= -1;
	}
	if (n < 16)
	{
		*len += write (1, &forme[n], 1);
	}
	else
	{
		ft_printhex(n / 16, x, len);
		ft_printhex(n % 16, x, len);
	}
}
