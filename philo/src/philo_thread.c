/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:12:03 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/09 14:56:42 by kwpark           ###   ########.fr       */
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
	while (i < ph->arg->n_philos)
		ph->arg->philos[i++].stop = 1;
	pthread_mutex_unlock(&ph->arg->print_mutex);
}

int	check_enough_to_eat(t_philo *ph)
{
	int	i;

	i = 0;
	if (!(ph->arg->num_to_eat > 0))
		return (0);
	while (i < ph->arg->n_philos)
	{
		if ((ph->arg->philos[i].n_eat < ph->arg->num_to_eat))
			return (0);
		i++;
	}
	i = 0;
	while (i < ph->arg->n_philos)
		ph->arg->philos[i++].stop = 1;
	return (1);
}

void	*ft_thread(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->philo_nbr % 2 == 0)
	{
		usleep(ph->arg->t_eat * 800);
	}
	while (!ph->arg->dead)
	{
		if ((ph->arg->dead || ph->stop))
			return (NULL);
		set_forks(ph);
		if ((ph->arg->dead || ph->stop))
		{
			pthread_mutex_unlock(ph->l_f);
			pthread_mutex_unlock(ph->r_f);
			return (NULL);
		}
		eating(ph);
		if ((ph->arg->dead || ph->stop))
			return (NULL);
		sleeping(ph);
		if ((ph->arg->dead || ph->stop))
			return (NULL);
		thinking(ph);
		if ((ph->arg->dead || ph->stop))
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
		{
			usleep(200);
			i = 0;
		}
		// pthread_mutex_lock(&args->dead_mutex);
		if (args->philos[i].stop == 1)
		{
			// pthread_mutex_unlock(&args->dead_mutex);
			break ;
		}
		// pthread_mutex_unlock(&args->dead_mutex);
		if (get_time() - args->philos[i].time > args->t_die)
		{
			philo_die(&args->philos[i]);
			break ;
		}
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
