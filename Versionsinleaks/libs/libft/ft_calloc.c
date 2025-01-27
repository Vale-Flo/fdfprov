/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:29:18 by vflores           #+#    #+#             */
/*   Updated: 2024/11/16 18:29:21 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The calloc() function allocates memory for an array of nmemb  elements
       of size bytes each and returns a pointer to the allocated memory.  The
       memory is set to zero.  If nmemb or size is 0, then  calloc()  returns
       either  NULL, or a unique pointer value that can later be successfully
       passed to free().  If the multiplication of nmemb and size  would  re‐
       sult  in  integer  overflow,  then calloc() returns an error.  By con‐
       trast, an integer overflow would not be detected in the following call
       to malloc(), with the result that an incorrectly sized block of memory
       would be allocated:

           malloc(nmemb * size)
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size && nmemb > (__SIZE_MAX__ / size))
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return ((unsigned char *)ptr);
}
