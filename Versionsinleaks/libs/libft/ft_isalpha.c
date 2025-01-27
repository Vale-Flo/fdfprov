/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:57:08 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 13:57:11 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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
printf("Vale = %d\n", ft_isalpha(argv[1]));
printf("Vrai fonction = %d\n", isalpha(argv[1]));
}
}
*/
