/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:57:52 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 14:12:52 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	printf("Vrai Fonction\n");
	char destin[23] = "";
	char source[23] = "";
	printf("\nBefore le destin est: |%s|\n", destin);

	// Fill 7 characters in destin
	memcpy(destin, source, 7*sizeof(char));
	printf("After le destin est:  |%s|\n", destin);

	printf("\nMa Fonction\n");
	char destin2[23] = "";
	char source2[23] = "";
	printf("\nBefore le destin est: |%s|\n", destin2);

	// Fill 7 characters in destin
	ft_memcpy(destin2, source2, 7*sizeof(char));
	printf("After le destin est:  |%s|\n", destin2);

	return 0;
}
*/
/*
   Hola Valeria, aca estoy
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
