/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:28:52 by vflores           #+#    #+#             */
/*   Updated: 2025/01/14 16:47:14 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/libft.h"
// #include "../include/ft_printf.h"
#include "libft.h"

int	ft_ptr_len(unsigned long num)
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

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
		print_length += write(1, "(nil)", 5);
	else
	{
		print_length += write(1, "0x", 2);
		ft_putnbr_base (ptr, "0123456789abcdef");
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}

/*
void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}
*/
// static int	ft_print_prefix(char *str)
// {
// 	int	i;

// 	i = ft_print_str(str);
// 	return (i);
// }

// int	ft_print_ptr(unsigned long long ptr)
// {
// 	int				i;
// 	char			*str;
// 	// unsigned long	address;

// 	// address = (unsigned long)ptr_address;
// 	i = ft_print_prefix("0x");
// 	str = ft_putnbr_base(ptr, "0123456789abcdef");
// 	i = i + ft_print_str(str);
// 	return (i);
// }
