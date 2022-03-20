/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:22:10 by cvine             #+#    #+#             */
/*   Updated: 2022/03/20 12:00:01 by cvine            ###   ########.fr       */
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
