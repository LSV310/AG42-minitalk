/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:40:07 by agruet            #+#    #+#             */
/*   Updated: 2025/02/10 12:40:48 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*create_str(char c)
{
	static char	*str;
	static int	i;
	char		*temp;

	str = ft_realloc(str, i + 1, i);
	if (!str)
		exit(1);
	str[i] = c;
	i++;
	if (c == 0)
	{
		temp = str;
		str = NULL;
		i = 0;
		return (temp);
	}
	return (NULL);
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;
	char		*str;

	if (sig == SIGUSR1)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		str = create_str(c);
		if (str)
		{
			ft_printf("%s\n", str);
			free(str);
			kill(info->si_pid, SIGUSR2);
		}
		bit = 0;
		c = 0;
	}
	else
		c <<= 1;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	init(&sa, handle_signal);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
