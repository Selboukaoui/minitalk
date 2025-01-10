/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:43:44 by selbouka          #+#    #+#             */
/*   Updated: 2024/11/23 15:46:54 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, int *len)
{
	if (n < 0)
	{
		*len += write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		n += 48;
		*len += write (1, &n, 1);
	}
	else
	{
		ft_putunbr(n / 10, len);
		ft_putunbr(n % 10, len);
	}
}
