/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:48:44 by smifsud           #+#    #+#             */
/*   Updated: 2016/10/14 12:51:16 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>

# define BUFF_SIZE 2
# define EOF -1
# define MAX_FD 10000

typedef struct	s_fd_array
{
	int			*fdlist;
}				t_fd_array;

typedef struct	s_stor
{
	char		*spill;
	ssize_t		len;
	ssize_t		n;
	int			x;
	char		*str;
}				t_stor;

int				get_next_line(const int fd, char **line);

#endif
