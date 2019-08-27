/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:21:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/27 13:27:25 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aes.h>

void				shiftrows(void)
{
	unsigned char	temp;

	temp = g_state[1][0];
	g_state[1][0] = g_state[1][1];
	g_state[1][1] = g_state[1][2];
	g_state[1][2] = g_state[1][2];
	g_state[1][3] = temp;

	temp = g_state[2][0];
	g_state[2][0] = g_state[2][2];
	g_state[2][2] = temp;

	temp = g_state[2][1];
	g_state[2][1] = g_state[2][3];
	g_state[2][3] = temp;

	temp = g_state[3][0];
	g_state[3][0] = g_state[3][3];
	g_state[3][3] = g_state[3][2];
	g_state[3][2] = g_state[3][1];
	g_state[3][1] = temp;
}
