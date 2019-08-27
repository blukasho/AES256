/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:15:47 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/27 22:29:21 by blukasho         ###   ########.fr       */
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

static void			print_key(void)
{
	int				i;

	i = -1;
	printf("g_key[]");
	while (++i < 32)
	{
		if (!(i % 4))
			printf("\n");
		printf("%-5c", g_key[i]);
	}
	printf("\n\n");
}

static void			print_output(void)
{
	int				i;

	i = ~0;
	printf("Output |");
	while (++i < 16)
		printf("%c", g_output[i]);
	printf("|\n");
}

int					main(void)
{
	initarrays();
	cipher();
	print_output();
	printf("Sorry, it doesn’t work, but I learned a lot. Thanks you!\n");
	return (0);
}
