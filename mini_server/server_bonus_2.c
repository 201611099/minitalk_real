/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:32:04 by hyojlee           #+#    #+#             */
/*   Updated: 2021/07/05 19:57:52 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	g_pid;

unsigned char	set_char(unsigned char bit, int get)
{
	static unsigned char	ch = 0;
	unsigned char			tmp;

	tmp = ch;
	if (get)
	{
		ch = 0;
		return (tmp);
	}
	ch = ch << 1;
	ch += bit;
	return (ch);
}

static void	handler(int signo, siginfo_t *siginfo, void *context)
{
	context = NULL;
	if (signo == SIGUSR1)
		set_char(1, 0);
	else if (signo == SIGUSR2)
		set_char(0, 0);
	g_pid = siginfo->si_pid;
}

static int	receive_integer(t_len *len)
{
	int	idx;

	idx = 0;
	while (idx < 32)
	{
		pause();
		if (++idx % 8 == 0)
			len->len[((32 - idx) / 8)] = set_char(0, 1);
	}
	return (len->msg_len);
}

static void	receive_info(t_len *c_pid)
{
	t_len	len;
	int		idx;
	char	*str;

	idx = 0;
	receive_integer(&len);
	str = (char *)malloc(sizeof(char) * (len.msg_len + 1));
	if (!str)
	{
		kill(c_pid->msg_len, SIGUSR2);
		exit(1);
	}
	str[len.msg_len] = '\0';
	while (idx < (len.msg_len * 8))
	{
		pause();
		if (++idx % 8 == 0)
			str[(idx / 8) - 1] = set_char(0, 1);
	}
	ft_putstr_fd(str, 1);
	free(str);
}

int	main(void)
{
	t_sigaction	act;
	t_len		c_pid;

	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
	{
		kill(c_pid.msg_len, SIGUSR2);
		exit(1);
	}
	while (1)
	{
		receive_integer(&c_pid);
		receive_info(&c_pid);
		ft_putchar_fd('\n', 1);
		usleep(1000);
		kill(g_pid, SIGUSR1);
	}
	return (0);
}
