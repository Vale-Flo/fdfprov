/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:28 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 14:00:34 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len_src;

	len_src = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len_src);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
/*
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("Vale = %d\n", ft_strlcpy(argv[1]));
		printf("Vrai fonction = %d\n", strlcpy(argv[1]));
	}
}
*/
