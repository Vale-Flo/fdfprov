/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:53:13 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 13:53:23 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
printf("Vale = %d\n", ft_isascii(argv[1]));
printf("Vrai fonction = %d\n", isascii(argv[1]));
}
}
*/
