/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:44:50 by kyork             #+#    #+#             */
/*   Updated: 2016/10/05 15:41:53 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CSI "\033["
#include <stdio.h>
#include <unistd.h>

int		g_colors[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14,
	16 + 5, 16 + 12, 16 + 23, 16 + 30, 52 + 0, 52 + 5, 52 + 6, 52 + 12, 52 + 20,
	88 + 1, 88 + 6, 88 + 12, 160 + 12, 196 + 30, 160 + 21};

int		main(void)
{
	char		c;
	ssize_t		read_size;

	while (1)
	{
		read_size = read(0, &c, 1);
		if (read_size == 0)
			break ;
		if ('A' <= c && c <= 'Z')
		{
			printf("%s48;5;%dm%c", CSI, g_colors[c - 'A'], c);
		}
		else if (c == '.')
			printf("%sm%c", CSI, c);
		else if (c == '\n')
			printf("%sm%c", CSI, c);
		else
			printf("%c", c);
}
}
