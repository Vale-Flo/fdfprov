/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:24:34 by vflores           #+#    #+#             */
/*   Updated: 2025/01/14 16:47:06 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/libft.h"
// #include "../include/ft_printf.h"
#include "libft.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_print_hex(unsigned int nbr, const char input)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else if (input == 'x')
	{
		ft_putnbr_base (nbr, "0123456789abcdef");
		return (ft_hex_len(nbr));
	}
	else if (input == 'X')
	{
		ft_putnbr_base (nbr, "0123456789ABCDEF");
		return (ft_hex_len(nbr));
	}
	return (0);
}
/*
int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}
*/
