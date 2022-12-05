/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:32:12 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/05 00:11:27 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	free_exit(t_philo *philos, int exit_sig)
{
	free(philos);
	exit(exit_sig);
}

void	kill_pids(t_args *args, int *pids)
{
	int	i;

	i = -1;
	while (++i < args->n_philos)
		kill(pids[i], SIGKILL);
	free(pids);
}
