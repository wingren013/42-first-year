/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:24:55 by kyork             #+#    #+#             */
/*   Updated: 2016/10/19 11:31:44 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <stdint.h>
# include <stdbool.h>

# define TET_INPUT_MAX 26
# define MALLOC_GUARD(x) if (!x) return (0)

typedef struct		s_tetmask {
	char			m[4];
}					t_tetmask;

/*
** for the rotation state names, http://harddrop.com/wiki/SRS
*/

typedef enum		e_tet
{
	TET_INVALID,
	TET_I_HZ,
	TET_I_VT,
	TET_J_0,
	TET_J_R,
	TET_J_2,
	TET_J_L,
	TET_L_0,
	TET_L_R,
	TET_L_2,
	TET_L_L,
	TET_O,
	TET_S_0,
	TET_S_R,
	TET_T_0,
	TET_T_R,
	TET_T_2,
	TET_T_L,
	TET_Z_0,
	TET_Z_R,
}					t_tet;

# define TET_ITER_START TET_I_HZ
# define TET_ITER_MAX (TET_Z_R + 1)

extern t_tetmask	g_tet_shapes[];
extern uint8_t		g_tet_widths[];
extern uint8_t		g_tet_heights[];

typedef struct		s_field {
	int				size;
	char			taken[];
}					t_field;

typedef struct		s_link	{
	enum e_tet		tet;
	bool			used;
	char			c;
}					t_link;

t_field				*new_field(int size);
t_field				*clone_field(t_field *f);

# define ROW(pos) (pos[0])
# define COL(pos) (pos[1])
# define IDX(row, col) ( ((row) * f->size) + (col) )

t_field				*find_solution(int size, t_link *tets);
t_field				*place_tet(t_field *f, t_link *tets, bool bf);

int					read_input(char *filename, t_link *tets);
t_tetmask			align_mask(t_tetmask mask);
bool				all_used(t_link *tets);

extern t_field		*g_best;

int					cmp_field(t_field *best, t_field *prop, bool partial);
void				report_solution(t_field *f);
void				print_solution(t_field *f);

#endif
