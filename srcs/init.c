/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 22:10:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/27 22:26:47 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aes.h>
static void		init_g_round_keys(void)
{
	g_round_keys = (unsigned char *)malloc(240 * sizeof(unsigned char));
	memset(g_round_keys, 0, sizeof(g_round_keys));
}

static void		init_g_output(void)
{
	g_output = (unsigned char *)malloc(16 * sizeof(unsigned char));
	memset(g_output, 0, sizeof(g_output));
}

void			initarrays(void)
{
	init_g_round_keys();
	init_g_output();
}
