/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:49 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 14:00:56 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** The ft_strlen() function computes the length of the string s.
 */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <string.h>
#include <stdio.h>
int main (int argc, char **argv)
{
	if (argc == 2)
	{
		printf("Vale = %d\n", ft_strlen(argv[1]));
		printf("Vrai fonction = %d\n", strlen(argv[1]));
	}
}
*/
