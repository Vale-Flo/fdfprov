/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:57:38 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 13:57:40 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("Vale = %d\n", ft_isprint(argv[1]));
		printf("Vrai fonction = %d\n", isprint(argv[1]));
	}
}
*/
