/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 08:59:15 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/28 09:01:59 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aes.h>

void			print_round_keys(void)
{
	int				i;

	i = -1;
	printf("\ng_round_keys[]");
	while (++i < 60)
	{
		if (!(i % 4))
			printf("\n");
		printf("%#-5x", g_round_keys[i]);
	}
	printf("\n");
}

void			print_key(void)
{
	int				i;

	i = -1;
	printf("KEY |");
	while (++i < 32)
	{
		if (!(i % 4))
			printf(" ");
		printf("%-5c", g_key[i]);
	}
	printf("|\n\n");
}

void			print_output(void)
{
	int				i;

	i = ~0;
	printf("Output |");
	while (++i < 16)
		printf("%c", g_output[i]);
	printf("|\n");
}
