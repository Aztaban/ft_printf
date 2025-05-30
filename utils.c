/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:45:47 by mjusta            #+#    #+#             */
/*   Updated: 2025/05/30 16:19:27 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	count;
	
	count = 0;
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}

int ft_putnbr(int n)
{
	unsigned int	num;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		num = (unsigned int)(-(long)n);
	}
	else
		num = (unsigned int)n;
	if (num >= 10)
		count += ft_putnbr(num / 10);
	count += ft_putchar(num % 10 + '0');
	return (count);
}

/* 
#include <stdio.h>
int	main(void)
{
	char	*str = "Hello 42";
	printf(" is %i characters long\n", ft_putstr(str));

	int		nb = -2147483648;
	printf(" is %i characters long\n", ft_putnbr(nb));
} */