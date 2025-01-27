/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:01:08 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 14:01:17 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (s1[i] == s2[i] && s1[i] != '\0'))
	{
		i++;
	}
	if (s1[i] != s2[i])
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

/*
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0' && s1[i] == s2[i] && s2[i] != '\0')
	{
		i++;
	}
	if (i == n)
	{
		return (s1[i - 1] - s2[i - 1]);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}
*/
/*
#include <stdio.h>
int	main(void)
{
char	mot1[] = "ABC";
char	mot2[] = "AB";
unsigned int	k;

k = 3;
printf("Manual says 67\n");
printf("%d\n", ft_strncmp(mot1, mot2, k));

char	mot3[] = "ABA";
char	mot4[] = "AB";
unsigned int    m;

m = 2;
printf("Manual says 0\n");
printf("%d\n", ft_strncmp(mot3, mot4, m));

}
*/

/* string_comp.c

   Licensed under GNU General Public License v2 or later.
   */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[])
{
int res;

if (argc < 3) {
fprintf(stderr, "Usage: %s <str1> <str2> [<len>]\n", argv[0]);
exit(EXIT_FAILURE);
}

if (argc == 3)
res = strcmp(argv[1], argv[2]);
else
res = strncmp(argv[1], argv[2], atoi(argv[3]));

if (res == 0) {
printf("<str1> and <str2> are equal");
if (argc > 3)
printf(" in the first %d bytes\n", atoi(argv[3]));
printf("\n");
} else if (res < 0) {
printf("<str1> is less than <str2> (%d)\n", res);
} else {
printf("<str1> is greater than <str2> (%d)\n", res);
}

exit(EXIT_SUCCESS);
}
*/
