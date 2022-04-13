/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:40 by cvine             #+#    #+#             */
/*   Updated: 2022/04/13 20:06:50 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	action(t_philo *philo, t_lifecycle action)
{
	print(philo, action);
	if (action == eating)
	{
		philo->last_meal_time = get_time() - philo->start_time;
		philo->num_of_meals++;
		if (philo->num_of_meals == philo->param[num_of_eating])
			sem_post(philo->meal);
		ft_usleep(philo->param[time_to_eat]);
	}
	else if (action == sleeping)
		ft_usleep(philo->param[time_to_sleep]);
}

void	simulation(t_philo	*philo, int id)
{
	pthread_t	death;

	philo->id = id;
	create_thread(philo, &death, death_control);
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
}
