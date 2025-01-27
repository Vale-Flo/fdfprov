/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:53:00 by vflores           #+#    #+#             */
/*   Updated: 2025/01/15 14:05:54 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/libft.h"
// #include "../include/ft_printf.h"
#include "libft.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	check_type(va_list args, const char input)
{
	int	len;

	len = 0;
	if (input == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (input == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (input == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (input == 'd' || input == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (input == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (input == 'x' || input == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), input);
	else if (input == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, input);
	if (!input)
		return (-1);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			len = len + check_type(args, input[i + 1]);
			// if (input[i + 1] == 0)
			// 	return (-1);
			i++;
		}
		else
		{
			len = len + ft_print_char(input[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}

//cc test_c.c -L. -lftprintf
// #include <stdio.h>
// int main ()
// {
// 	int n;
// 	n = 'c';
// 	int i = 0;
// 	int k = 0;

// 	printf("|Real fonction: %c|\n", n);
// 	ft_printf("|My fonction: %c|\n", n);
// 	i = printf("%c\n", n);
// 	k = ft_printf("%c\n", n);
// 	printf("Real count : %d\n", i);
// 	ft_printf("My count : %d\n", k);
// }
