/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:56:52 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 13:56:55 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
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
printf("Vale = %d\n", ft_isalnum(argv[1]));
printf("Vrai fonction = %d\n", isalnum(argv[1]));
}
}
*/
/**/
