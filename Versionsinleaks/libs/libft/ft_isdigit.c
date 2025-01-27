/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:57:24 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 13:57:26 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
		printf("Vale = %d\n", ft_isdigit(argv[1]));
		printf("Vrai fonction = %d\n", isdigit(argv[1]));
	}
}
*/
