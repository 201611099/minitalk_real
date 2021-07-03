/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:52:21 by hyojlee           #+#    #+#             */
/*   Updated: 2021/07/03 22:41:08 by lhj-unix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/libft.h"
# include <signal.h>

typedef union	u_len
{
	char	len[4];
	int	msg_len;
}		t_len;

#endif
