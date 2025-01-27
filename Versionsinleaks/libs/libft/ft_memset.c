/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:53:43 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 14:05:21 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = s;
	while (n > 0)
	{
		*tmp_ptr = c;
		tmp_ptr++;
		n--;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	printf("Vrai Fonction\n");
	char str[23] = "Hola Valeria, aca estoy";
	printf("\nBefore memset(): %s\n", str);

	// Fill 7 characters starting from str[5] with '#'
	memset(str + 5, '#', 7*sizeof(char));
	printf("After memset():  %s\n", str);

	printf("\nMa Fonction\n");
	char str2[23] = "Hola Valeria, aca estoy";
	printf("\nBefore memset(): %s\n", str2);
	ft_memset(str2 + 5, '#', 7*sizeof(char));
	printf("After memset():  %s\n", str2);
	return 0;
}
*/
//pourquoi probleme si je mets *str
