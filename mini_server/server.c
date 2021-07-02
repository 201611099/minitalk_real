/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:32:04 by hyojlee           #+#    #+#             */
/*   Updated: 2021/06/28 20:54:04 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		ft_putnbr(int n)
{
	char	s;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		s = n + '0';
		write(1, &s, 1);
	}
}

unsigned char	set_char(char bit, int init, int get)
{
	static unsigned char	ch = 0;

	if (get)
		return (ch);
	if (init)
		ch = 0;
	ch = ch << 1;
	ch += bit;
	return (ch);
}

void			handler(int signo)
{
	if (signo == SIGUSR1)
		set_char(1, 0, 0);
	else if (signo == SIGUSR2)
		set_char(0, 0, 0);
}

int				main(void)
{
	int				num;
	unsigned char	ch;

	num = 0;
	write(1, "Server pid: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	if (signal(SIGUSR1, handler) == SIG_ERR)
		exit(1);
	if (signal(SIGUSR2, handler) == SIG_ERR)
		exit(1);
	while (1)
	{
		pause();
		num++;
		if (num == 8)
		{
			ch = set_char(1, 0, 1);
			write(1, &ch, 1);
			set_char(0, 1, 0);
			num = 0;
		}
	}
	return (0);
}

