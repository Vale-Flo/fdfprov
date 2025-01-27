/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:30:47 by vflores           #+#    #+#             */
/*   Updated: 2025/01/14 16:47:28 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/libft.h"
// #include "../include/ft_printf.h"
#include "libft.h"

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n)
{
	char	*nbr;
	int		len;

	len = 0;
	nbr = ft_itoa(n);
	len = ft_print_str(nbr);
	free(nbr);
	return (len);
}
