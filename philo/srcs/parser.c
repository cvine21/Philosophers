/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:52:20 by cvine             #+#    #+#             */
/*   Updated: 2022/04/10 10:45:58 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_number(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_isnumber(argv[i]))
		{
			printf(RED"Error\nThe argument \"%s\" is not a number\n"COLOR_RESET,
				argv[i]);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	is_valid_argv(int index, int argv_int)
{
	if (index == 0 && !argv_int)
		printf(RED"Error\nThere must be at least 1 philosopher\n"COLOR_RESET);
	else if (index > 0 && index < 5 && argv_int < 0)
		printf(RED"Error\nThe argument cannot be negative\n"COLOR_RESET);
	else
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	*atoi_array(int argc, char **argv)
{
	int	i;
	int	*argv_int;

	i = 0;
	if (check_if_number(argv))
		return (NULL);
	argv_int = malloc(sizeof(int) * (argc - 1));
	if (!argv_int)
		return (NULL);
	while (argv[i])
	{
		argv_int[i] = ft_atoi(argv[i]);
		if (is_valid_argv(i, argv_int[i]))
			return (NULL);
		i++;
	}
	return (argv_int);
}

int	*parse(int argc, char **argv)
{
	int		*argv_int;

	if (argc < 5 | argc > 6)
	{
		printf("Invalid number of arguments.\n");
		return (NULL);
	}
	argv_int = atoi_array(argc, argv + 1);
	if (!argv_int)
		return (free_mem(NULL, NULL, NULL, argv_int));
	return (argv_int);
}
