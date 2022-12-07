/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:03:23 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/07 15:44:47 by kwpark           ###   ########.fr       */
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

struct	s_args;

typedef enum s_bool
{
	FAILURE = 1,
	SUCCESS = 0
}	t_bool;

typedef struct s_philo
{
	pthread_t		thr;
	int				n_eat;
	long			time;
	int				philo_nbr;
	int				stop;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;
	struct s_args	*arg;
}	t_philo;

typedef struct s_args
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_to_eat;
	int				dead;
	long			time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	n_eat_mutex;
	pthread_mutex_t	stop_mutex;
}	t_args;

long	get_time(void);
t_bool	check_args(int ac, char **av);
int		ft_atoi(const char *str);
void	ft_usleep(int ms);
t_bool	init(t_args *args, int ac, char **av);
void	set_forks(t_philo *ph);
void	eating(t_philo *ph);
void	sleeping(t_philo *ph);
void	thinking(t_philo *ph);
void	philo_thread(t_args *args);
void	all_mutex_destroy(t_args *args);
void	free_all(t_args *args);
int		check_n_eat(t_philo *ph, int i);
int		check_dead_stop(t_philo *ph);

#endif