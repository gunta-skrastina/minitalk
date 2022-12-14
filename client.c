/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gskrasti <gskrasti@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:56:44 by gskrasti          #+#    #+#             */
/*   Updated: 2022/09/11 17:35:16 by gskrasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_client_handler(int sig);
void	send_bit(char *message, pid_t pid);
void	ft_end_of_message(pid_t _pid);

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Wrong argument count\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (0);
	}
	signal(SIGUSR1, ft_client_handler);
	signal(SIGUSR2, ft_client_handler);
	send_bit(argv[2], pid);
	while (1)
		pause();
	return (0);
}

void	ft_client_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		usleep(500);
	}
	send_bit(0, 0);
}

void	send_bit(char *message, pid_t pid)
{
	static int				i = 8;
	static unsigned char	c;
	static char				*str;
	static pid_t			server_pid;
	static int				j = 0;

	if (message)
	{
		str = message;
		server_pid = pid;
		c = str[0];
	}
	if (i == 0)
	{
		i = 8;
		c = str[++j];
		if (c == '\0')
			ft_end_of_message(server_pid);
	}
	if (c && c >> --i & 1)
		kill(server_pid, SIGUSR1);
	else if (c)
		kill(server_pid, SIGUSR2);
}

void	ft_end_of_message(pid_t pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		usleep(500);
		kill(pid, SIGUSR2);
	}
	exit(0);
}
