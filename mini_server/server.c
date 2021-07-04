/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:32:04 by hyojlee           #+#    #+#             */
/*   Updated: 2021/07/04 17:35:54 by lhj-unix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

unsigned char	set_char(unsigned char bit, int get)
{
	static unsigned char	ch = 0;
	unsigned char		tmp;
	
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

void		handler(int signo)
{
	if (signo == SIGUSR1)
		set_char(1, 0, 0);
	else if (signo == SIGUSR2)
		set_char(0, 0, 0);
}

static void	repeat_receive(t_len *len)
{
	int idx;
	char *str;

	idx = 0;
	while (idx < 32)
	{
		pause();
		if (++idx % 8 == 0)
			len->len[((32 - idx) / 8)] = set_char(0, 1);
	}
	str = (char *)malloc(sizeof(char) * (len->msg_len + 1));
	if (!str)
		exit(1);
	idx = 0;
	str[len->msg_len] = '\0';
	while (idx < (len->msg_len * 8))
	{
		pause();
		if (++idx % 8 == 0)
			str[(idx / 8) - 1] = set_char(0, 1);
	}
	ft_putstr_fd(str, 1);
	free(str);
}

int		main(void)
{
	t_len	len;

	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	if (signal(SIGUSR1, handler) == SIG_ERR
			|| signal(SIGUSR2, handler) == SIG_ERR)
		exit(1);
	while (1)
	{
		repeat_receive(&len);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
