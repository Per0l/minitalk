/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:14:26 by aperol-h          #+#    #+#             */
/*   Updated: 2021/09/02 20:20:30 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "minitalk.h"

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_print("Response from server\n");
}

void	send_end_toserver(pid_t spid)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		kill(spid, SIGUSR2);
		i++;
		pause();
	}
}

void	send_string_toserver(pid_t spid, char *s)
{
	int		char_i;
	int		bit_i;
	char	cchar;

	char_i = 0;
	while (s[char_i])
	{
		cchar = s[char_i++];
		bit_i = 0;
		while (bit_i <= 8)
		{
			if (cchar & 0x01)
				kill(spid, SIGUSR1);
			else
				kill(spid, SIGUSR2);
			bit_i++;
			cchar >>= 1;
			pause();
		}
	}
	send_end_toserver(spid);
}

int	main(int argc, char **argv)
{
	pid_t	spid;

	if (argc == 3)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		spid = ft_atoi(argv[1]);
		if (spid <= 0 || spid > 4194304)
		{
			ft_print("Invalid pid!\n");
			return (0);
		}
		send_string_toserver(spid, argv[2]);
	}
	else
		ft_print("usage: ./client pid message\n");
	return (0);
}
