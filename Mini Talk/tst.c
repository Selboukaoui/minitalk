
#include <libc.h>


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

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	counter = 0;
	static int	result = 0;
	static int pid = 0;
	(void)context;
	
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		counter = 0;
		result = 0;
	}
	
	if (signum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - counter));
		// result = result | (1 << counter);
	counter++;
	
	if (counter == 8)
	{
		write (1,&result,1);
		usleep(50);
		counter = 0;
		result = 0;
	}
	usleep(50);

}

int	main(void)
{
	struct sigaction	samir;
	
	printf("Server's PID: %d\n", getpid());

	samir.sa_flags = SA_SIGINFO;
	samir.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &samir, NULL);
	sigaction(SIGUSR2, &samir, NULL);
	while (1)
		usleep(50);
	// samir.sa_flags = 0;
	// sigemptyset(&samir.sa_mask);
	// sigaddset(&samir.sa_mask, SIGUSR1);
	// sigaddset(&samir.sa_mask, SIGUSR2);
}

// -----------------------------


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
	static int	counter = 0;
	static int	result = 0;

	
	if (signum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - counter));
	counter++;
	if (counter == 8)
	{
		// final = letter_to_string(final, result);
		// if (result == '\0')
		// {
		// 	printf("%s\n", final);
		// 	final = NULL;
		// }
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




// -------------------------------------------------------------









#include <libc.h>

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

char	*letter_to_string(char const *s1, char const letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((strlen(s1) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free ((void *)(s1));
	return (tab);
}

void	signal_handler(int signum)
{
	static int	counter = 0;
	static int	result = 0;
	static int	len = 0;
	static char	*final;

	if (!final)
		final = strdup("");
	if (signum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - counter));
	counter++;
	if (counter == 8)
	{
		final = letter_to_string(final, result);
		if (result == '\0')
		{
			printf("%s\n", final);
			final = NULL;
		}
		counter = 0;
		result = 0;
		len += 1;
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