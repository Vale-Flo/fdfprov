/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:59:06 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 13:59:15 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("Ma fonction:\n");
		printf("|%s|\n", ft_strchr((argv[1]),(int)argv[2][0]));
		printf("La vrai fonction:\n");
		printf("|%s|\n", strchr(argv[1], (int)argv[2][0]));
	}
}
*/
