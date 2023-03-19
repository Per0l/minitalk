/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:12:02 by aperol-h          #+#    #+#             */
/*   Updated: 2021/09/02 20:13:37 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"

void	zero_byte(t_byte *sig_byte, pid_t cid, void *unused)
{
	(void)unused;
	sig_byte->b_i = 0;
	sig_byte->c = 0;
	sig_byte->cid = cid;
}

void	sig_handler(int sig, siginfo_t *info, void *unused)
{
	static t_byte	sig_byte;

	if (sig_byte.b_i < 0 || sig_byte.b_i > 8 || sig_byte.cid != info->si_pid)
		zero_byte(&sig_byte, info->si_pid, unused);
	if (sig_byte.b_i < 8)
	{
		if (sig == SIGUSR1)
			sig_byte.c |= (1 << sig_byte.b_i++);
		else if (sig == SIGUSR2)
			sig_byte.b_i++;
		usleep(1);
		kill(info->si_pid, SIGUSR2);
	}
	else
	{
		write(1, &sig_byte.c, 1);
		if (sig_byte.c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		zero_byte(&sig_byte, info->si_pid, unused);
		usleep(1);
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;
	char				*serverpid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	serverpid = ft_itoa(getpid());
	ft_print("PID: ");
	ft_print(serverpid);
	ft_print("\n");
	free(serverpid);
	while (1)
		continue ;
}
