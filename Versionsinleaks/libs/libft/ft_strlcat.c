/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:13 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 14:00:18 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dst);
	if (dstsize <= len_dest)
		return (len_src + dstsize);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1 - len_dest)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (len_src + len_dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int	main(void)
{
printf("%u\n", ft_strlcat("COmoesesto","Como", 5));
printf("real function : %zu\n", strlcat("COmoesesto","Como", 5));
printf("real function : %zu\n", strlcat("Comoesto","sandwich", 5));
printf("real function : %zu\n", strlcat("Comoesto","sandwich", 8));
printf("real function : %zu\n", strlcat("Sandwich","como", 5));
//printf("real function : %zu\n", strlcat("Loco","como", 5));
}
// pour tester cc ft_strlcat.c -lbsd
*/
