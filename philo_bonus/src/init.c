/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:58:21 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/07 16:16:16 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

t_bool	init(t_args *args, int ac, char **av)
{
	int	i;

	i = -1;
	args->n_philos = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	args->num_to_eat = -1;
	if (ac == 6)
		args->num_to_eat = ft_atoi(av[5]);
	args->time = get_time();
	args->philos = malloc(sizeof(t_philo) * args->n_philos);
	if (!args->philos)
		return (FAILURE);
	while (++i < args->n_philos)
	{
		args->philos[i].n_eat = 0;
		args->philos[i].time = args->time;
		args->philos[i].philo_nbr = i + 1;
		args->philos[i].arg = args;
	}
	return (SUCCESS);
}

t_bool	init_semaphore(t_args *args)
{
	sem_unlink("forks");
	sem_unlink("print_sem");
	sem_unlink("time_sem");
	sem_unlink("n_eat_sem");
	args->forks = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU, args->n_philos);
	args->print_sem = sem_open("print_sem", O_CREAT | O_EXCL, S_IRWXU, 1);
	args->time_sem = sem_open("time_sem", O_CREAT | O_EXCL, S_IRWXU, 1);
	args->n_eat_sem = sem_open("n_eat_sem", O_CREAT | O_EXCL, S_IRWXU, 1);
	if (args->forks == SEM_FAILED || args->print_sem == SEM_FAILED \
		|| args->time_sem == SEM_FAILED || args->n_eat_sem == SEM_FAILED)
	{
		free(args->philos);
		return (FAILURE);
	}
	return (SUCCESS);
}
