/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotword.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:51:13 by blukasho          #+#    #+#             */
/*   Updated: 2019/08/26 17:22:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aes.h>

void				rotword(unsigned char *word)
{
	unsigned char	tmp;

	tmp = word[0];
	word[0] = word[1];
	word[1] = word[2];
	word[2] = word[3];
	word[3] = tmp;
}
