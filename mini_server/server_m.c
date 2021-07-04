/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:32:04 by hyojlee           #+#    #+#             */
/*   Updated: 2021/07/04 16:33:42 by lhj-unix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

unsigned char	set_char(unsigned char bit, int init, int get)
{
	static unsigned char ch = 0;
	
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
	char *str;

	num = 0;
	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	if (signal(SIGUSR1, handler) == SIG_ERR)
		exit(1);
	if (signal(SIGUSR2, handler) == SIG_ERR)
		exit(1);
	while (num < 32)
	{
		pause();
		num++;
		if (num % 8 == 0)
		{
			len.len[((32 - num) / 8)] = set_char(1, 0, 1);
			set_char(0, 1, 0);
		}
	}
	set_char(0, 1, 0);
	str = (char *)malloc(sizeof(char) * (len.msg_len + 1));
	if (!str)
		exit(1);
	num = 0;
	str[len.msg_len] = '\0';
	while (num < (len.msg_len * 8))
	{
		pause();
		num++;
		if (num % 8 == 0)
		{
			str[(num / 8) - 1] = set_char(1, 0, 1);
			set_char(0, 1, 0);
		}
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (0);
}
