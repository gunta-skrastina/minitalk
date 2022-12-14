/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gskrasti <gskrasti@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:57:34 by gskrasti          #+#    #+#             */
/*   Updated: 2022/09/11 14:51:31 by gskrasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_server_handler(int sig, siginfo_t *sig_info, void *p);
static void	receive_message(int sig, pid_t pid);

int	main(void)
{
	struct sigaction	sa_server;
	pid_t				pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa_server.sa_flags = SA_SIGINFO;
	sa_server.sa_sigaction = ft_server_handler;
	sigaction(SIGUSR1, &sa_server, NULL);
	sigaction(SIGUSR2, &sa_server, NULL);
	while (1)
		pause();
	return (0);
}

static void	ft_server_handler(int sig, siginfo_t *info, void *ucontext)
{
	pid_t	pid;

	(void)ucontext;
	pid = info->si_pid;
	receive_message(sig, pid);
}

static void	receive_message(int sig, pid_t pid)
{
	static char	c = 0b00000000;
	static int	i = 0;

	if (sig == SIGUSR1)
		c = c | 1;
	if (++i == 8)
	{
		i = 0;
		if (c != 0b00000000)
		{
			ft_putchar(c);
			c = 0b00000000;
			kill(pid, SIGUSR1);
		}
	}
	else
	{
		c = c << 1;
		kill(pid, SIGUSR2);
	}
}
