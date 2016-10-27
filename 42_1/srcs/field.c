/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 13:19:17 by kyork             #+#    #+#             */
/*   Updated: 2016/10/07 14:25:28 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_field			*new_field(int size)
{
	t_field	*f;
	int		i;

	f = malloc(sizeof(t_field) + sizeof(char) * size * size);
	f->size = size;
	i = 0;
	while (i < size * size)
	{
		f->taken[i++] = 0;
	}
	return (f);
}

t_field			*clone_field(t_field *old)
{
	t_field	*f;
	int		i;

	f = malloc(sizeof(t_field) + sizeof(char) * old->size * old->size);
	f->size = old->size;
	i = 0;
	while (i < old->size * old->size)
	{
		f->taken[i] = old->taken[i];
		i++;
	}
	return (f);
}

static int		field_first(t_field *f, char c)
{
	int		pos;

	pos = 0;
	while (pos < (f->size * f->size))
	{
		if (f->taken[pos] == c)
			return (pos);
		pos++;
	}
	return (-1);
}

int				cmp_field(t_field *best, t_field *prop, bool partial)
{
	char	c;
	int		idx_a;
	int		idx_b;

	if (!best)
		return (-1);
	c = 'A' - 1;
	while (++c <= 'Z')
	{
		idx_a = field_first(best, c);
		idx_b = field_first(prop, c);
		if (idx_a < 0 && idx_b < 0)
			continue ;
		if (idx_b < 0)
			return (partial ? 0 : 1);
		if (idx_a < 0)
			return (-1);
		if (idx_a != idx_b)
			return (idx_b - idx_a);
	}
	return (0);
}

t_field			*g_best;

void			report_solution(t_field *f)
{
	if (cmp_field(g_best, f, false) < 0)
	{
		free(g_best);
		g_best = clone_field(f);
	}
}
