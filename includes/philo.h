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

typedef struct s_param
{
	int		*args;
	long	start_time;
	int		num_of_philos;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		each_philo_must_eat_times;
}	t_param;

typedef struct s_philo
{
	int				id;
	t_state			state;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}	t_philo;

int		check_if_number(char **argv);
int		*cast_argv_to_int(int argc, char **argv);
int		is_valid_argv(int index, int intArgv);

t_param	*init_params(int argc, char **argv);
long	get_time(void);
int		init_philo(int num_of_philos, pthread_mutex_t *fork);
int		init_simulation(int *args, t_param *param);

#endif