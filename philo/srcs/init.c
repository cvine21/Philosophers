/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:02 by cvine             #+#    #+#             */
/*   Updated: 2022/03/21 21:02:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_stuct_philo(int num_of_philos)
{
	int		i;
	t_philo	*philo;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * num_of_philos);
	if (!fork)
		return (NULL);
	philo = malloc(sizeof(t_philo) * num_of_philos);
	if (!philo)
		return (NULL);
	while (i < num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].state = thinking;
		philo[i].left_fork = fork[i];
		philo[i].right_fork = fork[(i + 1) % num_of_philos];
		pthread_mutex_init(fork + i, NULL);
		i++;
	}
	return (philo);
}

t_param	*init_struct_param(int argc, int *int_argv)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->num_of_philos = int_argv[0];
	param->die_time = int_argv[1];
	param->eat_time = int_argv[2];
	param->sleep_time = int_argv[3];
	param->start_time = get_time();
	if (argc == 6)
		param->each_philo_must_eat_times = int_argv[4];
	else
		param->each_philo_must_eat_times = -1;
	param->philo = init_stuct_philo(param->num_of_philos);
	return (param);
}
