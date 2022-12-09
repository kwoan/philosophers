/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:23:43 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/09 16:18:20 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	*ft_thread(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (!(ph->philo_nbr & 1))
		usleep(ph->arg->t_eat * 800);
	while (1)
	{
		set_forks(ph);
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
}

void	philo_action(t_philo *ph)
{
	pthread_t	thr;

	pthread_create(&thr, NULL, ft_thread, ph);
	pthread_detach(thr);
	while (1)
	{
		if (get_time() - ph->time > ph->arg->t_die)
		{
			sem_wait(ph->arg->print_sem);
			printf("%ld %d died\n", \
				get_time() - ph->arg->time, ph->philo_nbr);
			exit(1);
		}
		usleep(200);
	}
}

pid_t	*philo_process(t_args *args)
{
	pid_t	pid;
	pid_t	*pids;
	int		i;

	i = -1;
	if (init_semaphore(args))
		free_exit(args->philos, 1);
	pids = malloc(sizeof(pid_t) * args->n_philos);
	if (!pids)
		free_exit(args->philos, 1);
	while (++i < args->n_philos)
	{
		pid = fork();
		if (pid == 0)
			philo_action(&args->philos[i]);
		else if (pid == -1)
		{
			while (--i >= 0)
				kill(pids[i], SIGKILL);
			free_exit(args->philos, 1);
		}
		else
			pids[i] = pid;
	}
	return (pids);
}

void	ft_exit(t_args *args, int *pids, int size)
{
	int	status;
	int	i;

	if (size == args->n_philos)
		return (free(pids), free_exit(args->philos, 0));
	waitpid(-1, &status, 0);
	if ((status & 0x7f) == 0)
	{
		if ((((status) & 0xff00) >> 8) == 1)
		{
			i = -1;
			while (++i < args->n_philos)
				kill(pids[i], SIGKILL);
		}
		else
			return (ft_exit(args, pids, size + 1));
	}
	else
	{
		i = -1;
		while (++i < args->n_philos)
			kill(pids[i], SIGKILL);
	}
	return (free(pids), free_exit(args->philos, 0));
}
