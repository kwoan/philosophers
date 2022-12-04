/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:23:43 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/04 18:54:13 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	*ft_thread(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
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
			exit(1);
		if (ph->n_eat >= ph->arg->num_to_eat)
			exit(0);
	}
}

pid_t	*philo_process(t_args *args)
{
	pid_t	pid;
	pid_t	*pids;
	int		i;

	i = -1;
	if (init_semaphore(args))
		return (FAILURE);
	pids = malloc(sizeof(pid_t) * args->n_philos);
	if (!pids)
		return (FAILURE);
	while (++i < args->n_philos)
	{
		pid = fork();
		if (pid == 0)
			philo_action(&args->philos[i]);
		else
			pids[i] = pid;
	}
}