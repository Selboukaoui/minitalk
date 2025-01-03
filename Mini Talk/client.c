/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:45:15 by selbouka          #+#    #+#             */
/*   Updated: 2025/01/03 17:43:59 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <libc.h>


void send_signal(int pid, char *msg)
{
	int i;
	int j;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			if (((msg[i] >> (7 - j)) & 1) == 1)
				kill (pid,SIGUSR2);
			else if (((msg[i] >> (7 - j)) & 1) == 0)
				kill (pid,SIGUSR1);
			usleep(50);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill (pid, SIGUSR1);
		j++;
		usleep(50);
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_signal(atoi(argv[1]),argv[2]);
	}
	else
		write(1, "PID - MSG",9);
}