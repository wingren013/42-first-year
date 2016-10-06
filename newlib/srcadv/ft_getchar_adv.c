/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:09:48 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/24 20:59:35 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_getchar_adv(int fd, size_t n)
{
	unsigned char	buf;

	if (!read(fd, &buf, n))
		return (0);
	return (buf);
}
