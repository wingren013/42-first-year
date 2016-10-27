/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:09:55 by kyork             #+#    #+#             */
/*   Updated: 2016/10/07 14:25:58 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

#define USAGE "usage: fillit tetronimo_file\n"

int			usage(void)
{
	write(2, USAGE, sizeof(USAGE) - 1);
	return (64);
}

void		print_solution(t_field *f)
{
	int		i;
	int		j;

	i = 0;
	while (i < f->size)
	{
		j = 0;
		while (j < f->size)
		{
			if (f->taken[IDX(i, j)] == 0)
				write(1, ".", 1);
			else
				write(1, &f->taken[IDX(i, j)], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

t_field		*find_solution(int size, t_link *tets)
{
	t_field *f;
	t_field	*r;
	int		count;

	count = 0;
	while (tets[count].tet != TET_INVALID)
		count++;
	if (count * 4 > size * size)
		return (NULL);
	g_best = NULL;
	f = new_field(size);
	r = place_tet(f, tets, true);
	free(f);
	return (g_best);
}

int			main(int argc, char **argv)
{
	t_link	input[TET_INPUT_MAX + 1];
	t_field	*f;
	int		size;

	if (argc != 2)
		return (usage());
	if (EXIT_SUCCESS != read_input(argv[1], input))
	{
		write(1, "error\n", 6);
		return (EXIT_FAILURE);
	}
	size = 1;
	while (++size < 20)
	{
		if ((f = find_solution(size, input)) != NULL)
		{
			print_solution(f);
			return (EXIT_SUCCESS);
		}
	}
}
