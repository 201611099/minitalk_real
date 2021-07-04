/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:32:11 by hyojlee           #+#    #+#             */
/*   Updated: 2021/07/03 22:53:20 by lhj-unix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_send(unsigned char ch, int pid)
{
	unsigned char	now;
	unsigned char	before;
	int				idx;

	before = ch;
	idx = 0;
	while (idx < 8)
	{
		now = before << 1;
		if (now < before)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		before = now;
		idx++;
	}
}

int		main(int argc, char **argv)
{
	int				pid;
	unsigned int	idx;

	idx = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client server_pid message\n", 1);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	while (idx < ft_strlen(argv[2]))
		ft_send(argv[2][idx++], pid);
	return (0);
}
