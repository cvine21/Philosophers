/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:54:25 by cvine             #+#    #+#             */
/*   Updated: 2022/03/31 21:18:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simulation(void *tid)
{
	t_philo	*philo;

	philo = ((t_philo *)tid);
	if (philo->state == full)
		ft_usleep(philo->param->time_to_eat / 2);
	while (philo->num_of_meals != philo->param->each_philo_must_eat_times)
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

int	create_philo_threads(t_philo *philo, int num_of_philos)
{
	int			i;
	pthread_t	*philo_thread;

	i = -1;
	philo_thread = malloc(sizeof(pthread_t) * num_of_philos);
	if (!philo_thread)
		return (EXIT_FAILURE);
	while (++i < num_of_philos)
		pthread_create(&philo_thread[i],
			NULL, &simulation, (void *)(philo + i));
	i = -1;
	while (++i < num_of_philos)
		pthread_join(philo_thread[i], NULL);
	return (EXIT_SUCCESS);
}
