/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:43:28 by vflores           #+#    #+#             */
/*   Updated: 2025/01/14 16:47:21 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/libft.h"
// #include "../include/ft_printf.h"
#include "libft.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		print_length;

	print_length = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	else
	{
		ft_putnbr_base (nbr, "0123456789");
		print_length += ft_num_len(nbr);
	}
	return (ft_num_len(nbr));
}

// char	*ft_uitoa(unsigned int n)
// {
// 	char	*num;
// 	int		len;

// 	len = ft_num_len(n);
// 	num = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!num)
// 		return (0);
// 	num[len] = '\0';
// 	while (n != 0)
// 	{
// 		num[len - 1] = n % 10 + '0';
// 		n = n / 10;
// 		len--;
// 	}
// 	return (num);
// }

// int	ft_print_unsigned(unsigned int n)
// {
// 	int		print_length;
// 	char	*num;

// 	print_length = 0;
// 	if (n == 0)
// 		print_length += write(1, "0", 1);
// 	else
// 	{
// 		num = ft_uitoa(n);
// 		print_length += ft_print_str(num);
// 		free(num);
// 	}
// 	return (print_length);
// }
