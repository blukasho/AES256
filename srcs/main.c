/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:15:47 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/28 09:01:59 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aes.h>

int					main(void)
{
	initarrays();
	cipher();
	print_output();
	printf("Sorry, it doesn’t work, but I learned a lot. Thanks you!\n");
	return (0);
}
