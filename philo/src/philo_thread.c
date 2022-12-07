/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:12:03 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/07 15:52:10 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_die(t_philo *ph)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&ph->arg->dead_mutex);
	ph->arg->dead = 1;
	pthread_mutex_unlock(&ph->arg->dead_mutex);
	pthread_mutex_lock(&ph->arg->print_mutex);
	printf("%ld %d died\n", \
		get_time() - ph->arg->time, ph->philo_nbr);
	pthread_mutex_lock(&ph->arg->stop_mutex);
	while (i < ph->arg->n_philos)
		ph->arg->philos[i++].stop = 1;
	pthread_mutex_unlock(&ph->arg->stop_mutex);
	pthread_mutex_unlock(&ph->arg->print_mutex);
	all_mutex_destroy(ph->arg);
}

int	check_enough_to_eat(t_philo *ph)
{
	int	i;

	i = 0;
	if (!(ph->arg->num_to_eat > 0))
		return (0);
	while (i < ph->arg->n_philos)
	{
		if (check_n_eat(ph, i))
			return (0);
		i++;
	}
	i = 0;
	pthread_mutex_lock(&ph->arg->stop_mutex);
	while (i < ph->arg->n_philos)
		ph->arg->philos[i++].stop = 1;
	pthread_mutex_unlock(&ph->arg->stop_mutex);
	all_mutex_destroy(ph->arg);
	return (1);
}

void	*ft_thread(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (!ph->arg->dead)
	{
		if (check_dead_stop(ph))
			return (NULL);
		set_forks(ph);
		if (check_dead_stop(ph))
			return (NULL);
		eating(ph);
		if (check_dead_stop(ph))
			return (NULL);
		sleeping(ph);
		if (check_dead_stop(ph))
			return (NULL);
		thinking(ph);
		if (check_dead_stop(ph))
			return (NULL);
	}
	return (NULL);
}

void	*ft_monitor(void *arg)
{
	t_args	*args;
	int		i;

	args = (t_args *)arg;
	i = 0;
	while (1)
	{
		if (i == args->n_philos)
			i = 0;
		pthread_mutex_lock(&args->stop_mutex);
		if (args->philos[i].stop == 1)
			break ;
		pthread_mutex_unlock(&args->stop_mutex);
		pthread_mutex_lock(&args->time_mutex);
		if (get_time() - args->philos[i].time > args->t_die)
		{
			philo_die(&args->philos[i]);
			break ;
		}
		pthread_mutex_unlock(&args->time_mutex);
		if (check_enough_to_eat(args->philos))
			break ;
		i++;
	}
	return (NULL);
}

void	philo_thread(t_args *args)
{
	pthread_t	monitor_thr;
	int			i;

	i = -1;
	pthread_mutex_init(&args->print_mutex, NULL);
	pthread_mutex_init(&args->dead_mutex, NULL);
	pthread_mutex_init(&args->time_mutex, NULL);
	pthread_mutex_init(&args->n_eat_mutex, NULL);
	pthread_mutex_init(&args->stop_mutex, NULL);
	while (++i < args->n_philos)
		pthread_create(&args->philos[i].thr, NULL, \
			ft_thread, (void *)&args->philos[i]);
	pthread_create(&monitor_thr, NULL, ft_monitor, (void *)args);
	pthread_join(monitor_thr, NULL);
	if (args->n_philos == 1)
		pthread_mutex_unlock(&args->forks[0]);
	i = -1;
	while (++i < args->n_philos)
		pthread_join(args->philos[i].thr, NULL);
}
