/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:39:09 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/05 22:19:08 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void    set_forks(t_philo *ph)
{
    sem_wait(ph->arg->forks);
    sem_wait(ph->arg->print_sem);
    printf("%ld %d has taken a fork\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
	sem_post(ph->arg->print_sem);
    sem_wait(ph->arg->forks);
	sem_wait(ph->arg->print_sem);
    printf("%ld %d has taken a fork\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
    sem_post(ph->arg->print_sem);
}

void    eating(t_philo *ph)
{
    sem_wait(ph->arg->print_sem);
    printf("%ld %d is eating\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
    sem_post(ph->arg->print_sem);
    ph->time = get_time();
    ft_usleep(ph->arg->t_eat);
    sem_post(ph->arg->forks);
    sem_post(ph->arg->forks);
    ph->n_eat++;
}

void    sleeping(t_philo *ph)
{
    sem_wait(ph->arg->print_sem);
    printf("%ld %d is sleeping\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
    sem_post(ph->arg->print_sem);
    ft_usleep(ph->arg->t_sleep);
}

void    thinking(t_philo *ph)
{
    sem_wait(ph->arg->print_sem);
    printf("%ld %d is thinking\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
    sem_post(ph->arg->print_sem);
}
