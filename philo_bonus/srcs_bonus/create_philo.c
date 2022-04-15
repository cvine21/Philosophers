/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:38:41 by cvine             #+#    #+#             */
/*   Updated: 2022/04/15 13:59:50 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philo(t_philo *philo, int *param)
{
	int		i;
	pid_t	*pid;

	i = 0;
	pid = malloc(sizeof(pid_t) * param[num_of_philo]);
	if (!pid)
		exit(EXIT_FAILURE);
	while (i < param[num_of_philo])
	{
		pid[i] = fork();
		if (pid[i] == -1)
			exit(EXIT_FAILURE);
		else if (!pid[i])
		{
			simulation(philo, i + 1);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	while (i--)
		sem_post(philo->start);
	terminate(philo, param, pid);
}
