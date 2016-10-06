/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:09:48 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/24 21:00:08 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_getchar_fd(int fd)
{
	unsigned char	buf;

	if(!read(fd, &buf, 1))
		return (0);
	return (buf);
}
