/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:32:11 by vflores           #+#    #+#             */
/*   Updated: 2024/11/16 18:32:14 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + k] == little[k] && (i + k) < len)
		{
			if (little[k + 1] == '\0')
				return ((char *)&big[i]);
			k++;
		}
		k = 0;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%s\n", ft_strnstr("Holaa", "ol"));
	printf("%s\n", ft_strnstr("Holaa", "mo"));
	printf("%s\n", ft_strnstr("Holaa", "ok"));
	printf("Si on utlise la commande on a:\n");
	printf("%s\n", strnstr("Holaa", "ol"));
	printf("%s\n", strnstr("Holaa", "mo"));
	printf("%s\n", strnstr("Holaa", "ok"));
}
*/
