/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:01:30 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 14:01:36 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	while (len >= 0)
	{
		if (((char *)s)[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
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
		printf("|%s|\n", ft_strrchr((argv[1]),(int)argv[2][0]));
		printf("La vrai fonction:\n");
		printf("|%s|\n", strrchr(argv[1], (int)argv[2][0]));
	}
}
*/
