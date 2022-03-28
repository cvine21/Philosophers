/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:40 by cvine             #+#    #+#             */
/*   Updated: 2022/03/28 20:49:36 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*пока не работает и нигде не применяется*/
void	check_if_dead(t_philo *philo)
{
	long	time_from_last_meal;

	time_from_last_meal = get_time() - philo->last_meal_time;
	if (philo->state != eating
		&& time_from_last_meal > philo->param->time_to_die)
	{
		action(philo, die);
		exit(EXIT_FAILURE);
	}
}

void action(t_philo *philo, t_lifecycle action)
{
	int timestamp;

	timestamp = get_time() - philo->param->start_time;
	philo->state = action;
	if (action == take_forks)
	{
		printf(GREEN"%d %d has taken a fork\n"COLOR_RESET, timestamp, philo->id);
		printf(GREEN"%d %d has taken a fork\n"COLOR_RESET, timestamp, philo->id);
	}
	else if (action == eating)
	{
		printf(YELLOW"%d %d is eating\n"COLOR_RESET, timestamp, philo->id);
		ft_usleep(philo->param->time_to_eat);
		philo->last_meal_time = get_time();
		philo->num_of_meals++;
	}
	else if (action == sleeping)
	{
		printf(BLUE"%d %d is sleeping\n"COLOR_RESET, timestamp, philo->id);
		ft_usleep(philo->param->time_to_sleep);
	}
	else if (action == thinking)
		printf(MAGENTA"%d %d is thinking\n"COLOR_RESET, timestamp, philo->id);
	else
		printf(RED"%d %d died\n"COLOR_RESET, timestamp, philo->id);
}