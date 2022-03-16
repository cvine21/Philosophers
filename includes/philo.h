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
	hungry,
	eating,
	sleeping
}	t_state;

typedef struct s_arg
{
	unsigned int	philosophers_num;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	each_philo_must_eat_times;
}	t_arg;

typedef struct s_philo
{
	int				id;
	t_state			state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*rigt_fork;
}	t_philo;

int		check_if_number(char **argv);
int		*cast_argv_to_int(int argc, char **argv);
int		is_valid_argv(int index, int intArgv);

t_arg	*init_args(int argc, char **argv);

#endif