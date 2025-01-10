/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:04:08 by selbouka          #+#    #+#             */
/*   Updated: 2024/11/23 16:07:04 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *type, ...);
void	ft_putnbr(int n, int *len);
int		ft_putstr(char *s);
int		ft_putchar(int c);
void	ft_adress(void *n, int *len);
void	ft_putunbr(unsigned int n, int *len);
void	ft_printhex(unsigned int p, int x, int *len);

#endif 
