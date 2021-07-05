/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:32:11 by hyojlee           #+#    #+#             */
/*   Updated: 2021/07/05 10:55:26 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_subsend(unsigned char ch, int pid)
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
		usleep(100);
		before = now;
		idx++;
	}
}

void	ft_send(t_len *len, int pid, char *arg)
{
	int	i;

	i = 4;
	while (i-- > 0)
		ft_subsend((unsigned char)(len->len[i]), pid);
	usleep(30);
	i = 0;
	while (i < len->msg_len)
		ft_subsend(arg[i++], pid);
}

int	main(int argc, char **argv)
{
	int		pid;
	t_len	len;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client server_pid message\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	len.msg_len = ft_strlen(argv[2]);
	ft_send(&len, pid, argv[2]);
	return (0);
}
