/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:52:20 by cvine             #+#    #+#             */
/*   Updated: 2022/04/12 20:53:14 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_if_number(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_isnumber(argv[i]))
		{
			printf(RED"Error\nThe argument \"%s\" is not a number\n"DISCOLOR,
				argv[i]);
			exit(EXIT_FAILURE);
		}
	}
}

int	is_valid_argv(int index, int param)
{
	if (index == 0 && !param)
		printf(RED"Error\nThere must be at least 1 philosopher\n"DISCOLOR);
	else if (index > 0 && index < 5 && param < 0)
		printf(RED"Error\nThe argument cannot be negative\n"DISCOLOR);
	else
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	*atoi_array(int argc, char **argv)
{
	int	i;
	int	*param;

	i = 0;
	check_if_number(argv);
	param = malloc(sizeof(int) * ARGNUM);
	if (!param)
		return (NULL);
	while (argv[i])
	{
		param[i] = ft_atoi(argv[i]);
		if (is_valid_argv(i, param[i]))
			return (NULL);
		i++;
	}
	if (argc == 5)
		param[num_of_eating] = DEFAULT;
	return (param);
}

int	*parse(int argc, char **argv)
{
	int		*param;

	if (argc < 5 | argc > 6)
	{
		printf("Invalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	param = atoi_array(argc, argv + 1);
	if (!param)
		exit(EXIT_FAILURE);
	return (param);
}
