/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:45:15 by selbouka          #+#    #+#             */
/*   Updated: 2025/01/10 10:36:09 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "printf/ft_printf.h"

static int	skips(const char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		i;
	int		sign;
	long	tmp;

	nbr = 0;
	sign = 1;
	tmp = 0;
	i = skips(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = nbr;
		nbr = nbr * 10 + str[i] - '0';
		if (nbr / 10 != tmp && sign == 1)
			return (-1);
		else if (nbr / 10 != tmp && sign == -1)
			return (0);
		i++;
	}
	return ((int)nbr * sign);
}

void	send_signal(int pid, char c)
{
	int	j;

	j = 0;
	usleep(42);
	while (j++ < 8)
	{
		if (((c >> (8 - j)) & 1) == 1)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(255);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc != 3 || ft_atoi(argv[1]) == 0)
	{
		ft_printf ("\nNot valid input \t   ❌\nEnter:  ~ PID   MSG ~ ty   ✅\n");
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		usleep(42);
		i++;
	}
	send_signal(pid, '\0');
}
