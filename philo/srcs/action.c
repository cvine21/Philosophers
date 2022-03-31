/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:40 by cvine             #+#    #+#             */
/*   Updated: 2022/03/31 21:19:09 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death_check(t_philo *philo, int timestamp)
{
	if ((timestamp - philo->last_meal_time) > philo->param->time_to_die
		&& philo->state != eating)
	{
		printf(RED"%d %d died\n"COLOR_RESET, timestamp, philo->id);
		exit(EXIT_FAILURE);
	}
}

void	action(t_philo *philo, t_lifecycle action)
{
	int	timestamp;

	timestamp = get_time() - philo->param->start_time;
	philo->state = action;
	if (action == take_forks)
	{
		printf(GREEN"%d %d has taken a fork\n"COLOR_RESET, timestamp, philo->id);
		printf(GREEN"%d %d has taken a fork\n"COLOR_RESET, timestamp, philo->id);
	}
	else if (action == eating)
	{
		philo->last_meal_time = get_time() - philo->param->start_time;
		printf(YELLOW"%d %d is eating\n"COLOR_RESET, timestamp, philo->id);
		ft_usleep(philo->param->time_to_eat);
		philo->num_of_meals++;
	}
	else if (action == sleeping)
	{
		printf(BLUE"%d %d is sleeping\n"COLOR_RESET, timestamp, philo->id);
		ft_usleep(philo->param->time_to_sleep);
	}
	else
		printf(MAGENTA"%d %d is thinking\n"COLOR_RESET, timestamp, philo->id);
	death_check(philo, timestamp);
}
