/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:59:28 by vflores           #+#    #+#             */
/*   Updated: 2024/11/16 19:59:34 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freetab(char **tab, size_t j)
{
	while (j--)
	{
		if (tab[j])
			free(tab[j]);
	}
	free(tab);
}

//reconnaitre un word et separateur et compter words
int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count_word;

	i = 0;
	count_word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count_word++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count_word);
}

//dupliquer un word
char	*ft_sdup2(const char *src, char c)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**splitter(char **tab, char const *s, char c)
{
	size_t		i;
	size_t		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[k] = ft_sdup2(&s[i], c);
			if (!tab[k])
			{
				freetab(tab, k);
				return (NULL);
			}
			i++;
			k++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

//Nuestro split
char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = (char **) malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	return (splitter(tab, s, c));
}
/*
#include <stdio.h>
int	main()
{
int	i;
//	char *s = "lalal- lolo-lilil - ghj";
//	char *s = "----";
// char *s = "---------lalal- lolo-lilil - ghj";
// char	*sep= "-";
char	**arr;

i = 0;
arr = ft_split(" a uuuuuuub xxxcxxx ", 'x');
if (*arr == NULL)
printf("[0]\n");
while (arr[i])
{
printf("%s\n", arr[i]);
i++;
}
}
*/
