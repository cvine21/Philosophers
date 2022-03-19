/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:02 by cvine             #+#    #+#             */
/*   Updated: 2022/03/19 20:13:23 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(int num_of_philos, pthread_mutex_t *fork)
{
	int i;
	t_philo *philo;	

	i = 0;
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

t_param *init_params(int argc, char **argv)
{
	t_param	*param;
	int		*intArgv;

	intArgv = cast_argv_to_int(argc, argv + 1);
	if (!intArgv)
		return (NULL);

	param = malloc(sizeof(t_param));
	if (!param)
		return (NULL);

	param->args = intArgv;
	param->num_of_philos = intArgv[0];
	param->die_time = intArgv[1];
	param->eat_time = intArgv[2];
	param->sleep_time = intArgv[3];
	param->start_time = get_time();
	if (argc == 6)
		param->each_philo_must_eat_times = intArgv[4];
	else
		param->each_philo_must_eat_times = -1;
	return (param);
}

int init_simulation(int *args, t_param *param)
{
	pthread_mutex_t	*fork;
	t_philo			*philo;

	fork = malloc(sizeof(pthread_mutex_t) * args[0]);
	if (!fork)
		return (1);
	philo = init_philo(param->num_of_philos, fork);
	if (!philo)
		return (1);
	if (!create_philos(param->num_of_philos, philo))
		return (1);
	return (0);
}