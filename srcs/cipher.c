/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:58:40 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/27 21:05:57 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aes.h>

void	cipher(void)
{
	int	i;
	int	j;
	int	round;

	round = 0;
	for(i = 0; i < 4;i++)
		for(j = 0; j < 4;j++)
			g_state[j][i] = g_input[i * 4 + j];
	addroundkey(0);
	for(round = 1; round < NR;round++)
	{
		subbytes();
		shiftrows();
		mixcolumns();
		addroundkey(round);
	}
	subbytes();
	shiftrows();
	addroundkey(NR);
	for(i = 0; i < 4;i++)
		for(j = 0; j < 4;j++)
			g_output[i * 4 + j] = g_state[j][i];
}
