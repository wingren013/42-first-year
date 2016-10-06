/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:40:10 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/24 21:00:43 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	*ft_getmem(int fd, size_t n)
{
	unsigned char	*ret;

	ret = (unsigned char*)malloc(sizeof(unsigned char) * n);
	if (!read(fd, ret, n))
		return (0);
	return ((void*)ret);
}
