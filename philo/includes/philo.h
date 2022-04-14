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

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define DISCOLOR	"\x1b[0m"

typedef enum e_lifecycle
{
	hungry,
	full,
	take_forkss,
	eating,
	sleeping,
	thinking,
	died
}	t_lifecycle;

typedef struct s_param
{
	int				*argv_int;
	long			start_time;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				each_philo_must_eat;
	int				death_flag;
	pthread_mutex_t	print;
}	t_param;

typedef struct s_philo
{
	int				id;
	int				num_of_meals;
	long			last_meal_time;
	t_lifecycle		state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_param			*param;
}	t_philo;

int		*parse(int argc, char **argv);
void	*waiter_control(void *tid);
void	*simulation(void *tid);
int		create_threads(t_philo *philo, int num_of_philos);
void	*initialize(int argc, int *argv_int);

long	current_time(void);
void	ft_usleep(long millisec, t_philo *philo);
void	print(int timestamp, t_philo *philo, t_lifecycle action);
void	*free_mem(t_philo *philo, t_param *param, pthread_mutex_t *fork,
			int *argv_int);
int		ft_isnumber(char *str);
int		ft_atoi(const char *str);
#endif