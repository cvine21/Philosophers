/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:54:25 by cvine             #+#    #+#             */
/*   Updated: 2022/04/10 20:33:02 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	*meal_control(void *tid)
// {
// 	t_philo	*philo;

// 	philo = ((t_philo *)tid);
// 	while (1)
// 	{
// 		if (philo->num_of_meals == )
// 	}
// 	return (NULL);
// }

void	*death_control(void *tid)
{
	t_philo	*philo;
	int		timestamp;

	philo = ((t_philo *)tid);
	while (1)
	{
		timestamp = get_time() - philo->start_time;
		if ((timestamp - philo->last_meal_time) > philo->param[time_to_die])
		{
			print(timestamp, philo, died);
			sem_post(philo->stop_simul);
			return (NULL); 
		}
	}
	return (NULL);
}

void	create_threads(t_philo *philo)
{
	pthread_t	death;
	// pthread_t	meal;

	if (pthread_create(&death, NULL, &death_control, (void *)philo))
	{
		sem_post(philo->stop_simul);
		exit(EXIT_FAILURE);
	}
	if (pthread_detach(death))
	{
		sem_post(philo->stop_simul);
		exit(EXIT_FAILURE);
	}
	// if (pthread_create(&meal, NULL, &meal_control, (void *)philo))
	// 	return (EXIT_FAILURE);
	// if (pthread_detach(death))
	// 	return (EXIT_FAILURE);
}

int	create_philo_processes(int *param)
{
	int		i;
	pid_t	*pid;
	t_philo	*philo;

	i = 0;
	philo = init_philo(param);
	pid = malloc(sizeof(pid_t) * param[num_of_philo]);
	if (!pid)
		return (EXIT_FAILURE);
	while(i < param[num_of_philo])
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (EXIT_FAILURE);
		else if (!pid[i])
			simulation(philo, i + 1);
		i++;
	}
	sem_wait(philo->stop_simul);
	terminate(philo, param, pid);
	return (EXIT_SUCCESS);
}