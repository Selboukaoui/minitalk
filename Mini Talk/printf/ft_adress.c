/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:09:45 by selbouka          #+#    #+#             */
/*   Updated: 2024/11/23 15:46:22 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_adress(void *p, int *len)
{
	char			*forme;
	unsigned long	n;

	n = (unsigned long)p;
	forme = "0123456789abcdef";
	if (n < 16)
	{
		*len += write (1, &forme[n], 1);
	}
	else
	{
		ft_adress((void *)(n / 16), len);
		ft_adress((void *)(n % 16), len);
	}
}
