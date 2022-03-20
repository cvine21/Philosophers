/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:52:20 by cvine             #+#    #+#             */
/*   Updated: 2022/03/20 12:02:24 by cvine            ###   ########.fr       */
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
			printf("Error\nThe argument \"%s\" is not a number\n", argv[i]);
			return (1);
		}
	}
	return (0);
}

int	is_valid_argv(int index, int int_argv)
{
	if (index == 0 && int_argv < 2)
		printf("Error\nThere must be at least 2 philosophers\n");
	else if (index > 0 && index < 4 && int_argv < 0)
		printf("Error\nThe time value cannot be negative\n");
	else if (index == 4 && int_argv < 0)
		printf("Error\nEach philosopher must eat times cannot be negative\n");
	else
		return (0);
	return (1);
}

int	*cast_argv_to_int(int argc, char **argv)
{
	int	i;
	int	*int_argv;

	i = 0;
	if (check_if_number(argv))
		return (NULL);
	int_argv = malloc(sizeof(int) * (argc - 1));
	if (!int_argv)
		return (NULL);
	while (*argv)
	{
		int_argv[i] = ft_atoi(*argv);
		if (is_valid_argv(i, int_argv[i]))
			return (NULL);
		argv++;
		i++;
	}
	return (int_argv);
}
