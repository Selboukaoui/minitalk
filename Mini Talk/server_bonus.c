/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:32:43 by selbouka          #+#    #+#             */
/*   Updated: 2025/01/10 10:35:00 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "printf/ft_printf.h"

int	checkuni(unsigned char c)
{
	if (c < 0x80)
		return (1);
	else if ((c & 0xe0) == 0xc0)
		return (2);
	else if ((c & 0xf0) == 0xe0)
		return (3);
	else if ((c & 0xf8) == 0xf0)
		return (4);
	return (0);
}

int	printing(int *counter, char *result, int *pid, int *idx)
{
	static unsigned char	unicode[8];
	static int				b_nbr;

	if (++(*counter) == 8)
	{
		if (*idx == 0)
			b_nbr = checkuni(*result);
		unicode[(*idx)++] = *result;
		if (--b_nbr == 0)
		{
			unicode[*idx] = '\0';
			ft_printf("%s", unicode);
			*idx = 0;
			kill (*pid, SIGUSR1);
		}
		if (*result == '\0')
		{
			kill (*pid, SIGUSR2);
			write(1, "\n", 1);
		}
		*counter = 0;
		*result = 0;
	}
	return (0);
}

void	signal_handler(int signum, siginfo_t *info, void *vd)
{
	static int			counter;
	static char			result;
	static pid_t		pid;
	static int			idx;

	(void)vd;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		counter = 0;
		result = 0;
		idx = 0;
	}
	if (signum == SIGUSR2)
		result |= (0b10000000 >> counter);
	if (printing(&counter, &result, &pid, &idx) == 1)
		return ;
}

void	tag(void)
{
	char	*tg;

	tg = "\n"\
		"\n"
		"\t\t\t\t\t\t\t.___  ___.  __  .__   __.  __  "\
		".__________.    ___       __       __  ___ \n"
		"\t\t\t\t\t\t\t|   \\/   | |  | |  \\ "\
		"|  | |  | |          |   /   \\     |  |     |  |/  / \n"
		"\t\t\t\t\t\t\t|  \\  /  | |  | |   \\"\
		"|  | |  | `---|  |---`  /  ^  \\    |  |     |  '  /  \n"
		"\t\t\t\t\t\t\t|  |\\/|  | |  | |  . `  | "\
		"|  |     |  |     /  /_\\  \\   |  |     |    <   \n"
		"\t\t\t\t\t\t\t|  |  |  | |  | |  |\\   | "\
		"|  |     |  |    /  _____  \\  |  `----.|  .  \\  \n"
		"\t\t\t\t\t\t\t|__|  |__| |__| |__| \\__|"\
		" |__|  .  |__|   /__/     \\__\\ |_______||__|\\__\\ \n\n";
	ft_printf ("%s\n\t\t\t\t\t\t\t\t\t\t     1 3 3 7 ", tg);
}

int	main(void)
{
	struct sigaction	samir;

	tag();
	ft_printf("\n   Server PID 📜 →  \t%d\n", getpid());
	samir.sa_sigaction = signal_handler;
	samir.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &samir, 0);
	sigaction(SIGUSR2, &samir, 0);
	while (1)
		pause();
	return (0);
}
