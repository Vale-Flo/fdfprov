/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:49:38 by vflores           #+#    #+#             */
/*   Updated: 2024/11/16 19:49:45 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src [j];
		j++;
	}
	dest [i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_tot;
	char	*return_strs;

	if (s1 && s2)
	{
		len_tot = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
		return_strs = malloc (len_tot * sizeof(char));
		if (return_strs == NULL)
			return (NULL);
		return_strs[0] = '\0';
		ft_strcat(return_strs, (char *)s1);
		ft_strcat(return_strs, (char *)s2);
		return (return_strs);
	}
	else
	{
		return_strs = (char *)malloc(sizeof(char));
		return_strs[0] = '\0';
		return (return_strs);
	}
}

/*
#include <stdio.h>
int	main(void)
{
int	s = 4;
char	*strs[5];
char	*sep = " ";

strs[0] = "hola";
strs[1] = "como";
strs[2] = "estas";
strs[3] = "?";

printf("%s\n", ft_strjoin(s, strs, sep));
return (0);

//	int	s = 0;
}
*/
