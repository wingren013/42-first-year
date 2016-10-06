/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicktest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:07:05 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/24 21:37:06 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main()
{
	long nc;
	char	**ptr;

	ptr = (char**)malloc(20);
	nc = 0;
	printf("%ld\n", sizeof(ptr));
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}
