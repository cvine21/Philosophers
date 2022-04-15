/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:40 by cvine             #+#    #+#             */
/*   Updated: 2022/04/15 16:46:06 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	action(t_philo *philo, t_lifecycle action)
{
	print(philo, action);
	if (action == eating)
	{
		philo->last_meal_time = current_time();
		philo->num_of_meals++;
		ft_usleep(philo->param[time_to_eat]);
	}
	else if (action == sleeping)
		ft_usleep(philo->param[time_to_sleep]);
}

void	simulation(t_philo	*philo, int philo_id)
{
	create_waiter(philo);
	sem_wait(philo->start);
	philo->id = philo_id;
	philo->start_time = current_time();
	philo->last_meal_time = current_time();
	if (!(philo_id % 2))
		ft_usleep(philo->param[time_to_eat]);
	while (philo->num_of_meals != philo->param[num_of_meals])
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
	sem_post(philo->stop);
	exit(EXIT_SUCCESS);
}
