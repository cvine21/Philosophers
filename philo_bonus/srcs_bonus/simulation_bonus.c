/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:40 by cvine             #+#    #+#             */
/*   Updated: 2022/04/10 20:31:13 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	create_threads(philo);
	philo->id = id;
	if (!(id % 2))
		ft_usleep(philo->param[time_to_eat] / 2);
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
