/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:41:00 by kyork             #+#    #+#             */
/*   Updated: 2016/10/07 14:17:05 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdbool.h>

bool		check_tet(t_field *f, enum e_tet t, int pos[2])
{
	int		x;
	int		y;

	if ((ROW(pos) + g_tet_heights[t] > f->size) ||
			(COL(pos) + g_tet_widths[t] > f->size))
		return (false);
	y = 0;
	while (y < 4)
	{
		x = -1;
		while (++x < 4)
			if (g_tet_shapes[t].m[y] & (1 << x))
			{
				if (f->taken[IDX(ROW(pos) + y, COL(pos) + x)] != 0)
					return (false);
			}
		y++;
	}
	return (true);
}

void		apply_tet(t_field *f, t_link *tets, int tidx, int pos[2])
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = -1;
		while (++x < 4)
			if (g_tet_shapes[tets[tidx].tet].m[y] & (1 << x))
			{
				f->taken[IDX(ROW(pos) + y, COL(pos) + x)] = tets[tidx].c;
			}
		y++;
	}
	tets[tidx].used = true;
}

void		undo_tet(t_field *f, t_link *tets, int tidx, int pos[2])
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = -1;
		while (++x < 4)
			if (g_tet_shapes[tets[tidx].tet].m[y] & (1 << x))
			{
				f->taken[IDX(ROW(pos) + y, COL(pos) + x)] = 0;
			}
		y++;
	}
	tets[tidx].used = false;
}

bool		first_position(t_field *f, t_link *tets, int tidx, int pos[2])
{
	pos[0] = 0;
	while (pos[0] < f->size)
	{
		pos[1] = 0;
		while (pos[1] < f->size)
		{
			if (check_tet(f, tets[tidx].tet, pos))
				return (true);
			pos[1]++;
		}
		pos[0]++;
	}
	return (false);
}

t_field		*place_tet(t_field *f, t_link *tets, bool best_first)
{
	int			pos[2];
	int			tidx;
	int			used_shapes;

	if (all_used(tets))
		report_solution(f);
	if (cmp_field(g_best, f, true) > 0)
		return (NULL);
	tidx = -1;
	used_shapes = 0;
	while (tets[++tidx].tet != TET_INVALID)
	{
		if (tets[tidx].used || (used_shapes & (1 << tets[tidx].tet)))
			continue ;
		if (!first_position(f, tets, tidx, pos))
			return (NULL);
		apply_tet(f, tets, tidx, pos);
		place_tet(f, tets, best_first);
		undo_tet(f, tets, tidx, pos);
		if ((used_shapes |= (1 << tets[tidx].tet)) && best_first && g_best != 0)
			return (g_best);
		best_first = false;
	}
	return (NULL);
}
