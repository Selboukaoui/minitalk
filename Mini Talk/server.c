/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:45:19 by selbouka          #+#    #+#             */
/*   Updated: 2025/01/10 09:42:52 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "printf/ft_printf.h"

static int	g_cpunter;

void	signal_handler(int signum, siginfo_t *info, void *vd)
{
	static char		result;
	static pid_t	pid;

	(void)vd;
	if (pid == 0)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		pid = 0;
		g_cpunter = 0;
		result = 0;
	}
	if (signum == SIGUSR2)
		result |= (0b10000000 >> g_cpunter);
	if (++g_cpunter == 8)
	{
		g_cpunter = 0;
		if (result == '\0')
		{
			write (1, "\n", 1);
			return ;
		}
		write (1, &result, 1);
		result = 0;
	}
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
