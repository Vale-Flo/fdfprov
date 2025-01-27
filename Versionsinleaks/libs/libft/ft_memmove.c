/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:58:07 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 13:58:25 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  memmove()  function  copies n bytes from memory area src to memory
       area dest.  The memory areas may overlap: copying takes place as though
       the  bytes in src are first copied into a temporary array that does not
       overlap src or dest, and the bytes are then copied from  the  temporary
       array to dest.

RETURN VALUE
       The memmove() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if ((size_t)dest - (size_t)src < n && src <= dest)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*

#include <string.h>
#include <stdio.h>

int main()
{
	printf("Vrai Fonction\n");
	char destin[23] = "Hola Valeria, aca estoy";
	char source[23] = "HOLA";
	printf("\nBefore le destin est: |%s|\n", destin);

	// Fill 7 characters in destin
	memmove(destin, source, 4*sizeof(char));
	printf("After le destin est:  |%s|\n", destin);

	   printf("\nMa Fonction\n");
	   char destin2[23] = "Hola Valeria, aca estoy";
	   char source2[23] = "HOLA";
	   printf("\nBefore le destin est: |%s|\n", destin2);

	// Fill 7 characters in destin
	ft_memmove(destin2, source2, 7*sizeof(char));
	printf("After le destin est:  |%s|\n", destin2);

	return 0;
}
*/
/*
#include <stdlib.h>
int main(int argc, char **argv)
{
if (argc == 4)
{
char* destin = argv[1];
char* destin2 = argv[1];
char* src1 = argv[2];
char* src2 = argv[2];
printf("Vrai Fonction\n");
printf("\nBefore le destin est: |%s|\n", destin);
memcpy(destin, src1, atoi(argv[3]));
printf("After le destin est:  |%s|\n", destin);

printf("\nMa Fonction\n");
printf("\nBefore le destin est: |%s|\n", destin2);
ft_memcpy(destin2, src2, atoi(argv[3]));
printf("After le destin est:  |%s|\n", destin2);

}
}
*/
