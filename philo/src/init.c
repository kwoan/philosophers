/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:38:53 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/02 06:36:20 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	_init(t_args *args)
{
	int	i;

	i = -1;
	args->dead = 0;
	args->time = get_time();
	while (++i < args->n_philos)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		args->philos[i].n_eat = 0;
		args->philos[i].time = args->time;
		args->philos[i].philo_nbr = i + 1;
		args->philos[i].stop = 0;
		args->philos[i].arg = args;
	}
	i = -1;
	while (++i < args->n_philos)
	{
		args->philos[i].r_f = &args->forks[i];
		args->philos[i].l_f = &args->forks[(i + 1) % args->n_philos];
	}
}

t_bool	init(t_args *args, int ac, char **av)
{
	args->n_philos = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	args->num_to_eat = -1;
	if (ac == 6)
		args->num_to_eat = ft_atoi(av[5]);
	args->philos = malloc(sizeof(t_philo) * args->n_philos);
	if (!args->philos)
		return (FAILURE);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->n_philos);
	if (!args->forks)
		return (free(args->philos), FAILURE);
	_init(args);
	return (SUCCESS);
}
