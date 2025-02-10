/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:40:05 by agruet            #+#    #+#             */
/*   Updated: 2025/02/10 12:47:39 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_count;

void	acknowledge(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		g_count++;
	else
	{
		ft_printf("Fini 😉\n");
		exit(1);
	}
}

void	send_0(pid_t pid)
{
	int	i;
	int	before;

	i = 0;
	while (i < 8)
	{
		before = g_count;
		kill(pid, SIGUSR2);
		while (before == g_count)
			pause();
		i++;
	}
}

void	send_message(pid_t pid, char *msg)
{
	char	c;
	int		bit;
	int		i;
	int		before;

	i = 0;
	while (msg[i])
	{
		c = msg[i];
		bit = 0;
		while (bit < 8)
		{
			before = g_count;
			if (c & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (before == g_count)
				pause();
			c <<= 1;
			bit++;
		}
		i++;
	}
	send_0(pid);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa1;
	struct sigaction	sa2;

	if (ac != 3)
	{
		if (ac > 3)
			ft_fprintf(2, "Too many arguments\n");
		else if (ac < 3)
			ft_fprintf(2, "Missing arguments\n");
		ft_fprintf(2, "Prototype: ./client <server PID> <message>\n");
		return (1);
	}
	pid = ft_atoi_natural(av[1]);
	if (pid == -1)
	{
		ft_fprintf(2, "Syntax error in PID: %s\n", av[1]);
		ft_fprintf(2, "Prototype: ./client <server pid> <message>\n");
	}
	init(&sa1, acknowledge);
	init(&sa2, acknowledge);
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	send_message(pid, av[2]);
	return (0);
}
