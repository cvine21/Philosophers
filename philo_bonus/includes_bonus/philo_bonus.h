/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:56:47 by cvine             #+#    #+#             */
/*   Updated: 2022/04/15 16:46:06 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define DISCOLOR	"\x1b[0m"

# define MAXARGC	5
# define DEFAULT	-1

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
	num_of_meals
}	t_param;

typedef struct s_philo
{
	int		id;
	int		num_of_meals;
	long	last_meal_time;
	long	start_time;
	int		*param;
	sem_t	*start;
	sem_t	*stop;
	sem_t	*forks;
	sem_t	*print;
}	t_philo;

int		*parse(int argc, char **argv);
void	simulation(t_philo	*philo, int philo_id);
void	create_philo(t_philo *philo, int *param);
void	create_waiter(t_philo *philo);
t_philo	*init_philo(int *param);

long	current_time(void);
void	ft_usleep(long millisec);
void	print(t_philo *philo, t_lifecycle action);
void	terminate(t_philo *philo, int *param, pid_t *pid);
int		ft_isnumber(char *str);
int		ft_atoi(const char *str);

#endif