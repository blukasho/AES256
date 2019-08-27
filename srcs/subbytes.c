/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subbytes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:11:52 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/27 22:18:56 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aes.h>

void	subbytes(void)
{
	int	i;
	int	j;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			g_state[i][j] = g_sbox[g_state[i][j]];
		}
	}
}
