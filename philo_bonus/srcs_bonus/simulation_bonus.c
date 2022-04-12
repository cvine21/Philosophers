/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:40 by cvine             #+#    #+#             */
/*   Updated: 2022/04/12 21:42:11 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*meal_counter(void *tid)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = ((t_philo *)tid);
	// while (i++ < philo->param[num_of_eating])
	sem_wait(philo->meal);
	sem_wait(philo->print);
	sem_post(philo->stop);
	return (NULL);
}

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
			print(philo, died);
			sem_post(philo->stop);
			return (NULL);
		}
	}
	return (NULL);
}

void	create_threads(t_philo *philo)
{
	pthread_t	death;
	pthread_t	meal;

	if (pthread_create(&death, NULL, &death_control, (void *)philo))
		exit(EXIT_FAILURE);
	if (pthread_detach(death))
		exit(EXIT_FAILURE);
	if (philo->param[num_of_eating] == DEFAULT)
		return ;
	if (pthread_create(&meal, NULL, &meal_counter, (void *)philo))
		exit(EXIT_FAILURE);
	if (pthread_detach(meal))
		exit(EXIT_FAILURE);
}

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
}
