/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:54:25 by cvine             #+#    #+#             */
/*   Updated: 2022/04/05 17:58:43 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_someone_dead(void *tid)
{
	t_philo	*philo;
	int		timestamp;

	philo = ((t_philo *)tid);
	while (1)
	{
		if (philo->param->death_flag)
		{
			timestamp = get_time() - philo->param->start_time;
			print(philo, died, "died");
			return(NULL);
		}
	}
	return (NULL);
}

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
	return (EXIT_SUCCESS);
}

int create_threads(t_philo *philo)
{
	pthread_t death;

	if (pthread_create(&death, NULL, &check_someone_dead, (void *)philo))
		return (EXIT_FAILURE);
	if (create_philo_threads(philo, philo->param->num_of_philos))
		return (EXIT_FAILURE);
	if (pthread_join(death, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}