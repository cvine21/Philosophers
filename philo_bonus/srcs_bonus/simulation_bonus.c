/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:40 by cvine             #+#    #+#             */
/*   Updated: 2022/04/07 15:57:47 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*waiter_control(void *tid)
{
	t_philo	*philo;
	int		timestamp;

	philo = ((t_philo *)tid);
	while (philo->num_of_meals != philo->param->each_philo_must_eat)
	{
		timestamp = get_time() - philo->param->start_time;
		if ((timestamp - philo->last_meal_time) > philo->param->time_to_die
			&& philo->state != eating)
		{
			print(timestamp, philo, died);
			return (NULL);
		}
	}
	return (NULL);
}

void	action(t_philo *philo, t_lifecycle action)
{
	int	timestamp;

	timestamp = get_time() - philo->param->start_time;
	philo->state = action;
	print(timestamp, philo, action);
	if (action == eating)
	{
		philo->last_meal_time = get_time() - philo->param->start_time;
		ft_usleep(philo->param->time_to_eat, philo);
		philo->num_of_meals++;
	}
	else if (action == sleeping)
		ft_usleep(philo->param->time_to_sleep, philo);
}

void	*simulation(void *tid)
{
	t_philo	*philo;

	philo = ((t_philo *)tid);
	if (philo->state == full)
		ft_usleep(philo->param->time_to_eat, philo);
	while (philo->num_of_meals != philo->param->each_philo_must_eat
		&& !philo->param->death_flag && philo->param->num_of_philos != 1)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		action(philo, take_forks);
		action(philo, eating);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		action(philo, sleeping);
		action(philo, thinking);
	}
	return (NULL);
}
