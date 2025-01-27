/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:56:36 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 14:05:48 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = s;
	while (n > 0)
	{
		*tmp_ptr = '\0';
		tmp_ptr++;
		n--;
	}
	return ;
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	printf("Vrai Fonction\n");
	char str[23] = "Hola Valeria, aca estoy";
	printf("\nBefore: |%s|\n", str);

	// Fill 7 characters starting from str[5] with '#'
	bzero(str + 5, 7*sizeof(char));
	printf("After:  |%s|\n", str);

	printf("\nMa Fonction\n");
	char str2[23] = "Hola Valeria, aca estoy";
	printf("\nBefore: |%s|\n", str2);
	ft_bzero(str2 + 5, 7*sizeof(char));
	printf("After:  |%s|\n", str2);
	return 0;
}
*/
//pourquoi probleme si je mets *str
