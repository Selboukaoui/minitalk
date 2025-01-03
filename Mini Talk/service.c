/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:45:19 by selbouka          #+#    #+#             */
/*   Updated: 2025/01/03 21:41:09 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <libc.h>


// char	*letter_to_string(char const *s1, char const letter)
// {
// 	int		i;
// 	int		j;
// 	char	*tab;

// 	i = 0;
// 	j = 0;
// 	tab = malloc((strlen(s1) + 2) * sizeof(char));
// 	if (!tab)
// 		return (NULL);
// 	while (s1[i])
// 		tab[j++] = s1[i++];
// 	i = 0;
// 	tab[j++] = letter;
// 	tab[j] = 0;
// 	free ((void *)(s1));
// 	return (tab);
// }

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else
	{
		res = nb * ft_recursive_power(nb, power - 1);
		return (res);
	}
}

void	signal_handler(int signum)
{
	static int	counter = 1;
	static char	result = 0;

	
	if (signum == SIGUSR2)
		result = result | (1 << counter);
	counter++;
	if (counter == 8)
	{
		if (result == 0)
		{
			write (1,"\n",1);
		}
		else
			write (1,&result,1);
		usleep(50);
		counter = 0;
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	samir;
	
	printf("Server's PID: %d\n", getpid());
	
	samir.sa_handler = signal_handler;
	samir.sa_flags = 0;
	sigaction(SIGUSR1, &samir, NULL);
	sigaction(SIGUSR2, &samir, NULL);
	while (1)
		usleep(50);
}