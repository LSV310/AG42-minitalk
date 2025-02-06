/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:40:07 by agruet            #+#    #+#             */
/*   Updated: 2025/02/06 18:06:03 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	printf("%d\n", sig);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa1;

	pid = getpid();
	ft_printf("%d\n", pid);
	init(&sa1, handle_signal);
	sigaction(SIGUSR1, &sa1, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
