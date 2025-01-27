/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:44:59 by vflores           #+#    #+#             */
/*   Updated: 2025/01/14 16:49:58 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/libft.h"
// #include "../include/ft_printf.h"
#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(unsigned long long nb, char *base)
{
	unsigned long long	len_base;

	len_base = ft_strlen(base);
	if (nb < len_base)
		ft_putchar(base[nb]);
	if (nb >= len_base)
	{
		ft_putnbr_base(nb / len_base, base);
		ft_putnbr_base(nb % len_base, base);
	}
	return ;
}

/*
#include <stdio.h>
int	main(void)
{
	char	*base1 = "0123456789ABCDEFA";
	printf("%d\n", ft_verif_base(base1));


	char    *base2 = "0123456789ABCDEF";
	printf("%d\n", ft_verif_base(base2));

	char    *base3 = "poneyvif";

	int	n;
	int	n2;

	n = 7;
	ft_putnbr_base(n, base1);
	printf("\n");
	ft_putnbr_base(n, base1);
	printf("\n");

	n = 7;
	ft_putnbr_base(n, base2);
	printf("\n");
	ft_putnbr_base(n, base3);
	printf("\n");

	n2 = 328;
	ft_putnbr_base(n2, base2);
	printf("\n");
	ft_putnbr_base(n2, base3);
	printf("\n");
}
*/
/*
#include <stdlib.h>
int	main(int argc, char **argv)
{
if (argc == 3)
{
ft_putnbr_base(atoi(argv[1]), argv[2]);
}
}
*/
