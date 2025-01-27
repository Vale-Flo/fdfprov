/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:38:02 by vflores           #+#    #+#             */
/*   Updated: 2025/01/15 11:21:30 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_digits(int n)
{
	size_t	i;

	i = 1;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	num;
	size_t		digits;
	char		*str_n;

	num = n;
	digits = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str_n = malloc((digits + 1) * sizeof(char));
	if (!str_n)
		return (NULL);
	*(str_n + digits) = 0;
	while (digits--)
	{
		*(str_n + digits) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*(str_n + 0) = '-';
	return (str_n);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int i = 0;
// 	int tab[5] = {-2147483648, -42, 0, 42, 2147483647};

// 	while (i < 5)
// 		printf("%s\n", ft_itoa(tab[i++]));

// 	return 0;
// }
