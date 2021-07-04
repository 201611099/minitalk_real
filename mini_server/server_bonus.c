/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:32:04 by hyojlee           #+#    #+#             */
/*   Updated: 2021/07/04 15:10:19 by lhj-unix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

unsigned int	set_char(unsigned int bit, int init, int get)
{
	static unsigned int	ch = 0;

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
	t_len	len;

	num = 0;
	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	if (signal(SIGUSR1, handler) == SIG_ERR)
		exit(1);
	if (signal(SIGUSR2, handler) == SIG_ERR)
		exit(1);
	while (1)
	{
		pause();
		num++;
		if (num == 32)
		{
			len.msg_len = set_char(1, 0, 1);
			ft_putstr_fd(len.len, 1);
			set_char(0, 1, 0);
			num = 0;
		}
	}
	return (0);
}

