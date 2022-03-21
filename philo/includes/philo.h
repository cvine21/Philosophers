/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:25:06 by cvine             #+#    #+#             */
/*   Updated: 2022/03/12 18:26:18 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef enum e_state
{
	thinking,
	eating,
	sleeping
}	t_state;

typedef struct s_philo
{
	int				id;
	t_state			state;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}	t_philo;

typedef struct s_param
{
	long	start_time;
	int		num_of_philos;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		each_philo_must_eat_times;
	t_philo *philo;
}	t_param;

int		*parse(int argc, char **argv);
long	get_time(void);

t_param	*init_struct_param(int argc, int *int_argv);
int		create_philo_threads(int num_of_philos, t_philo *philo);

#endif