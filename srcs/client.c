/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:40:05 by agruet            #+#    #+#             */
/*   Updated: 2025/02/06 18:07:04 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t pid, char *msg)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(200);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

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
	send_message(pid, av[2]);
	return (0);
}
