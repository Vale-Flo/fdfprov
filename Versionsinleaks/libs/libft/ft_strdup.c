/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:59:32 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 13:59:43 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
       The  strdup() function returns a pointer to a new string which is a du‐
       plicate of the string s.  Memory for the new string  is  obtained  with
       malloc(3), and can be freed with free(3).
*/
// dans malloc le nombre de items = size + 1
// car on oit compter le caractere null de la fin

char	*ft_strdup(const char *s)
{
	int		size_s;
	int		i;
	char	*dup;

	size_s = ft_strlen(s);
	dup = malloc((size_s + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	dup[size_s] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
if (argc == 2)
{
printf("%s\n", ft_strdup(argv[1]));
}
}
*/
