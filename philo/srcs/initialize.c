/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:02 by cvine             #+#    #+#             */
/*   Updated: 2022/04/10 10:45:58 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_param	*init_param(int argc, int *argv_int)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->argv_int = argv_int;
	param->num_of_philos = argv_int[0];
	param->time_to_die = argv_int[1];
	param->time_to_eat = argv_int[2];
	param->time_to_sleep = argv_int[3];
	param->start_time = get_time();
	param->death_flag = 0;
	param->each_philo_must_eat = -1;
	if (argc == 6)
		param->each_philo_must_eat = argv_int[4];
	pthread_mutex_init(&param->print, NULL);
	return (param);
}

t_philo	*init_philo(t_param *param, pthread_mutex_t *fork)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * param->num_of_philos);
	if (!philo)
		return (NULL);
	while (i < param->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].state = (philo[i].id + 1) % 2;
		philo[i].num_of_meals = 0;
		philo[i].last_meal_time = 0;
		philo[i].left_fork = fork + i;
		philo[i].right_fork = fork + ((i + 1) % param->num_of_philos);
		philo[i].param = param;
		pthread_mutex_init(fork + i, NULL);
		i++;
	}
	return (philo);
}

void	*initialize(int argc, int *argv_int)
{
	t_param			*param;
	t_philo			*philo;
	pthread_mutex_t	*fork;

	param = init_param(argc, argv_int);
	if (!param)
		return (free_mem(NULL, NULL, NULL, argv_int));
	fork = malloc(sizeof(pthread_mutex_t) * param->num_of_philos);
	if (!fork)
		return (free_mem(NULL, param, NULL, argv_int));
	philo = init_philo(param, fork);
	if (!philo)
		return (free_mem(NULL, param, fork, argv_int));
	if (create_threads(philo, philo->param->num_of_philos))
		return (free_mem(philo, param, fork, argv_int));
	free_mem(philo, param, fork, argv_int);
	return ((void *)EXIT_SUCCESS);
}
