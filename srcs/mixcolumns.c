/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixcolumns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:10:46 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/27 20:57:25 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aes.h>

void				mixcolumns(void)
{
	int				i;
	unsigned char	tmp_one;
	unsigned char	tmp_two;
	unsigned char	state_buf;

	for(i = 0; i < 4; i++)
	{
		state_buf = g_state[0][i];
		tmp_one = g_state[0][i] ^ g_state[1][i] ^ g_state[2][i] ^ g_state[3][i];
		tmp_two = g_state[0][i] ^ g_state[1][i]; tmp_two = mixcolumnsmodul(tmp_two);
		g_state[0][i] ^= tmp_two ^ tmp_one;
		tmp_two = g_state[1][i] ^ g_state[2][i]; tmp_two = mixcolumnsmodul(tmp_two);
		g_state[1][i] ^= tmp_two ^ tmp_one;
		tmp_two = g_state[2][i] ^ g_state[3][i]; tmp_two = mixcolumnsmodul(tmp_two);
		g_state[2][i] ^= tmp_two ^ tmp_one;
		tmp_two = g_state[3][i] ^ state_buf;
		tmp_two = mixcolumnsmodul(tmp_two); g_state[3][i] ^= tmp_two ^ tmp_one;
	}
}
