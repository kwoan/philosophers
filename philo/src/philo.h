/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:03:23 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/27 00:51:20 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef enum
{
	FALSE = 0,
	TRUE = 1
} t_bool;

typedef struct s_philo
{
	pthread_t   philo;
	int         n_eat;
	long        time;
	int         philo_idx;
	t_args      *args;
}   t_philo;


typedef struct  s_args
{
	int             n_philos;
	int             t_die;
	int             t_eat;
	int				t_sleep;
	int				die;
	int				stop;
	t_philo			*philos;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
}   t_args;

long    get_time(void);
t_bool  check_in(int ac, char **av);

#endif