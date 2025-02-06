/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:40:07 by agruet            #+#    #+#             */
/*   Updated: 2025/02/06 15:30:40 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	(void)sig;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa1;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa1.sa_handler = handle_signal;
	sa1.sa_sigaction = NULL;
	sa1.sa_flags = 0;
	sigemptyset(&sa1.sa_mask);
	// sigaction(SIGUSR1, &sa1, NULL);
	while (1)
	{
		// pause();
	}
	return (0);
}