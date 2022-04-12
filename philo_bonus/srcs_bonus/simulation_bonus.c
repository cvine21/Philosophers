/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:40 by cvine             #+#    #+#             */
/*   Updated: 2022/04/12 13:42:08 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death_control(void *tid)
{
	t_philo	*philo;
	long	timestamp;

	philo = ((t_philo *)tid);
	while (1)
	{
		timestamp = get_time() - philo->start_time;
		if ((timestamp - philo->last_meal_time) > philo->param[time_to_die])
		{
			print(timestamp, philo, died);
			sem_post(philo->stop);
			return (NULL);
		}
	}
	return (NULL);
}

void	create_threads(t_philo *philo)
{
	pthread_t	death;

	if (pthread_create(&death, NULL, &death_control, (void *)philo))
	{
		sem_post(philo->stop);
		exit(EXIT_FAILURE);
	}
	if (pthread_detach(death))
	{
		sem_post(philo->stop);
		exit(EXIT_FAILURE);
	}
}

void	action(t_philo *philo, t_lifecycle action)
{
	int	timestamp;

	timestamp = get_time() - philo->start_time;
	philo->state = action;
	print(timestamp, philo, action);
	if (action == eating)
	{
		philo->last_meal_time = get_time() - philo->start_time;
		ft_usleep(philo->param[time_to_eat]);
		philo->num_of_meals++;
	}
	else if (action == sleeping)
		ft_usleep(philo->param[time_to_sleep]);
}

void	simulation(t_philo	*philo, int id)
{
	philo->id = id;
	create_threads(philo);
	if (!(id % 2))
		ft_usleep(philo->param[time_to_eat]);
	while (1)
	{
		sem_wait(philo->forks);
		sem_wait(philo->forks);
		action(philo, take_forks);
		action(philo, eating);
		sem_post(philo->forks);
		sem_post(philo->forks);
		action(philo, sleeping);
		action(philo, thinking);
	}
	exit(EXIT_SUCCESS);
}
