/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:39:09 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/09 16:22:47 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	set_forks(t_philo *ph)
{
	sem_wait(ph->arg->forks);
	print_out(ph, "has taken a fork");
	sem_wait(ph->arg->forks);
	print_out(ph, "has taken a fork");
}

void	eating(t_philo *ph)
{
	sem_wait(ph->arg->time_sem);
	ph->time = print_out(ph, "is eating");
	sem_post(ph->arg->time_sem);
	ft_usleep(ph->time, ph->arg->t_eat);
	sem_post(ph->arg->forks);
	sem_post(ph->arg->forks);
	ph->n_eat++;
	if (ph->arg->num_to_eat > 0)
		if (ph->n_eat >= ph->arg->num_to_eat)
			exit(0);
}

void	sleeping(t_philo *ph)
{
	long	time;

	time = print_out(ph, "is sleeping");
	ft_usleep(time, ph->arg->t_sleep);
}

void	thinking(t_philo *ph)
{
	print_out(ph, "is thinking");
}
