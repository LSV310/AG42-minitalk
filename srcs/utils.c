/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:57:18 by agruet            #+#    #+#             */
/*   Updated: 2025/02/06 13:03:45 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi_natural(const char *nptr)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (nptr[i] == '\0')
		return (-1);
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i++] - '0');
		if (result > INT_MAX)
			return (-1);
	}
	if (nptr[i] != '\0')
		return (-1);
	return (result);
}
