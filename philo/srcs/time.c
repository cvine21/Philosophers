/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:22:10 by cvine             #+#    #+#             */
/*   Updated: 2022/04/06 20:56:13 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	current_time;
	long			millisec_time;

	gettimeofday(&current_time, NULL);
	millisec_time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (millisec_time);
}

void	ft_usleep(long millisec, t_philo *philo)
{
	long	current_time;

	current_time = get_time();
	while (get_time() - current_time < millisec && !philo->param->death_flag
			&& philo->num_of_meals != philo->param->each_philo_must_eat)
		usleep(300);
}
