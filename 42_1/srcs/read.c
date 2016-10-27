/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 12:55:47 by smifsud           #+#    #+#             */
/*   Updated: 2016/10/07 14:02:30 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define CHAR_BLANK '.'
#define CHAR_SET '#'
#define CLOSE_AND_RETURN(fd, code) {close(fd); return (code);}

int				parse_chars(char *buf, t_tetmask *mask, int is_eof)
{
	int			row;
	int			col;

	row = -1;
	while (++row < 4)
	{
		mask->m[row] = 0;
		col = 0;
		while (col < 4)
		{
			if (buf[row * 5 + col] == CHAR_SET)
				mask->m[row] |= (1 << col);
			else if (buf[row * 5 + col] != CHAR_BLANK)
				return (1);
			col++;
		}
		if (buf[row * 5 + 4] != '\n')
			return (1);
	}
	if (!is_eof && buf[20] != '\n')
		return (1);
	return (0);
}

t_tetmask		align_mask(t_tetmask mask)
{
	int		i;

	i = 4;
	while (mask.m[0] == 0 && i-- > 0)
	{
		mask.m[0] = mask.m[1];
		mask.m[1] = mask.m[2];
		mask.m[2] = mask.m[3];
		mask.m[3] = 0;
	}
	i = 4;
	while (!(mask.m[0] & 1) && !(mask.m[1] & 1) && !(mask.m[2] & 1) &&
			!(mask.m[3] & 1) && i-- > 0)
	{
		mask.m[0] >>= 1;
		mask.m[1] >>= 1;
		mask.m[2] >>= 1;
		mask.m[3] >>= 1;
	}
	return (mask);
}

t_link			parse_tet(char *buf, int is_eof, char c)
{
	t_tetmask	mask;
	enum e_tet	i;

	if (0 != parse_chars(buf, &mask, is_eof))
		return ((t_link){TET_INVALID, false, '~'});
	mask = align_mask(mask);
	i = TET_ITER_START;
	while (i < TET_ITER_MAX)
	{
		if (0 == ft_memcmp(mask.m, g_tet_shapes[i].m, sizeof(t_tetmask)))
			return ((t_link){(enum e_tet)i, false, c});
		i++;
	}
	return ((t_link){TET_INVALID, false, '~'});
}

int				read_input(char *filename, t_link *tets)
{
	int		fd;
	int		tet_num;
	size_t	read_size;
	char	buf[21];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	tet_num = 0;
	while (1)
	{
		read_size = read(fd, buf, 21);
		if ((read_size != 20 && read_size != 21) || tet_num == TET_INPUT_MAX)
			CLOSE_AND_RETURN(fd, 1);
		tets[tet_num] = parse_tet(buf, read_size == 20, 'A' + tet_num);
		if (tets[tet_num++].tet == TET_INVALID)
			CLOSE_AND_RETURN(fd, 1);
		if (read_size == 20)
			break ;
	}
	tets[tet_num].tet = TET_INVALID;
	read_size = read(fd, buf, 1);
	if (read_size != 0)
		CLOSE_AND_RETURN(fd, 1);
	CLOSE_AND_RETURN(fd, 0);
}
