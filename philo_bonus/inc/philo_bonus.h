/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:03:23 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/04 18:54:29 by kwpark           ###   ########.fr       */
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
# include <semaphore.h>

struct	s_args;

typedef enum s_bool
{
	FAILURE = 1,
	SUCCESS = 0
}	t_bool;

typedef struct s_philo
{
	int				n_eat;
	long			time;
	int				philo_nbr;
	struct s_args	*arg;
}	t_philo;

typedef struct s_args
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_to_eat;
	long			time;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*print_sem;
}	t_args;

long	get_time(void);
t_bool	check_args(int ac, char **av);
int		ft_atoi(const char *str);
void	ft_usleep(int ms);
t_bool	init(t_args *args, int ac, char **av);

t_bool	init_semaphore(t_args *args);

pid_t	*philo_process(t_args *args);

void	set_forks(t_philo *ph);
void	eating(t_philo *ph);
void	sleeping(t_philo *ph);
void	thinking(t_philo *ph);

#endif