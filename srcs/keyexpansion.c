/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyexpansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:05:37 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/27 12:00:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aes.h>

void			keyexpansion(void)
{
	signed int	i;
	signed int	k;
	unsigned char	temp[4];

	for(i = 0; i < NK; i++)
	{
		g_round_keys[i * 4 + 0] = g_key[i * 4 + 0];
		g_round_keys[i * 4 + 1] = g_key[i * 4 + 1];
		g_round_keys[i * 4 + 2] = g_key[i * 4 + 2];
		g_round_keys[i * 4 + 3] = g_key[i * 4 + 3];
	}
	print_round_keys();

	while (i < (NB * (NR + 1)))
	{
		for(k = 0; k < 4; k++)
			temp[k] = g_round_keys[i - 1 * 4 + k];
		if (i % NK == 0)
		{
			rotword(temp);
			subword(temp);
			temp[0] = temp[0] ^ g_rcon[i/NK];
		}
		else if (i % NK == 4)
			subword(temp);
		g_round_keys[i * 4 + 0] = g_round_keys[(i - NK) * 4 + 0] ^ temp[0];
		g_round_keys[i * 4 + 1] = g_round_keys[(i - NK) * 4 + 1] ^ temp[1];
		g_round_keys[i * 4 + 2] = g_round_keys[(i - NK) * 4 + 2] ^ temp[2];
		g_round_keys[i * 4 + 3] = g_round_keys[(i - NK) * 4 + 3] ^ temp[3];
		++i;
	}
}
