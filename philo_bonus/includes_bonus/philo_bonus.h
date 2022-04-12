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

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "libft.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define DISCOLOR	"\x1b[0m"

# define ARGNUM			5
# define DEFAULT		-1

typedef enum e_lifecycle
{
	take_forks,
	eating,
	sleeping,
	thinking,
	died
}	t_lifecycle;

typedef enum e_param
{
	num_of_philo,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	num_of_eating
}	t_param;

typedef struct s_philo
{
	int			id;
	int			num_of_meals;
	long		last_meal_time;
	long		start_time;
	int			*param;
	t_lifecycle	state;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*meal;
	sem_t		*stop;
}	t_philo;

int		*parse(int argc, char **argv);
void	simulation(t_philo	*philo, int id);
int		create_processes(t_philo *philo, int *param);
t_philo	*init_philo(int *param);

long	get_time(void);
void	ft_usleep(long millisec);
void	print(t_philo *philo, t_lifecycle action);
void	terminate(t_philo *philo, int *param, pid_t *pid);

#endif