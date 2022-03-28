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

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

# include "libft.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef enum e_lifecycle
{
	hungry,
	full,
	take_forks,
	eating,
	sleeping,
	thinking,
	die
}	t_lifecycle;

typedef struct s_param
{
	long	start_time;
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		each_philo_must_eat_times;
}	t_param;

typedef struct s_philo
{
	int				id;
	t_lifecycle		state;
	int				num_of_meals;
	long			last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_param			*param;
}	t_philo;

int		*parse(int argc, char **argv);
long	get_time(void);
void	ft_usleep(long millisec);

t_philo	*init(int argc, int *int_argv);
int		create_philo_threads(t_philo *philo, int num_of_philos);

void	action(t_philo *philo, t_lifecycle action);
#endif