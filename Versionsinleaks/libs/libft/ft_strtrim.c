/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:01:51 by vflores           #+#    #+#             */
/*   Updated: 2024/11/12 14:01:56 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//reconnaitre un set
int	ft_is_a_set(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

//on cherche le debut du s1
unsigned int	ft_start(const char *str, const char *charset)
{
	unsigned int	i;

	i = 0;
	while (ft_is_a_set(str[i], charset) == 1 && str[i])
		i++;
	return (i);
}

//on cherche la fin du s1
unsigned int	ft_end(const char *str, const char *charset)
{
	unsigned int	len;
	unsigned int	start;

	start = ft_start(str, charset);
	len = ft_strlen(str);
	while (ft_is_a_set(str[len - 1], charset) == 1 && len > 0 && start < len)
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	size_t			len_s1;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	len_s1 = end - start;
	return (ft_substr(s1, start, len_s1));
}
