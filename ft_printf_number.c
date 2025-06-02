/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:15:23 by mjusta            #+#    #+#             */
/*   Updated: 2025/06/02 14:49:20 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long n, const char *base, unsigned int blen)
{
	int		count;

	count = 0;
	if (n >= blen)
		count += ft_putnbr_base(n / blen, base, blen);
	count += ft_putchar(base[n % blen]);
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789", 10));
}

int	ft_puthex(unsigned int n, int upper)
{
	if (upper)
		return (ft_putnbr_base(n, "0123456789ABCDEF", 16));
	else
		return (ft_putnbr_base(n, "0123456789abcdef", 16));
}

int	ft_putpointer(void *ptr)
{
	unsigned long	address;
	int				count;

	count = 0;
	address = (unsigned long)ptr;
	if (!address)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base(address, "0123456789abcdef", 16);
	}
	return (count);
}
