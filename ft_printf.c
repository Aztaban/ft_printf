/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:47:27 by mjusta            #+#    #+#             */
/*   Updated: 2025/06/02 11:51:44 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int))); 
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, int)));
/* 	else if (specifier == "p")
		// print void pointer in hexadecimal format
		return ;  */
	else if (specifier == 'x')
		return (ft_puthex(va_arg(args, int), 0)); 
	else if (specifier == 'X')
		return (ft_puthex(va_arg(args, int), 1));
	else if (specifier == '%')
		return (ft_putchar(va_arg(args, int)));
 	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	va_start(args, input);
	count = 0;
	while (*input)
	{
		if (*input == '%')
			count += handle_conversion(*(++input), args);
		else
			count += ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (count);
}

/* #include <stdio.h>
int main(void)
{
	int ft1 = ft_printf("Hello 42%\n");
	int og1 = printf("Hello 42%\n");
	printf("ft length is %i!\n", ft1);
	printf("og length is %i!\n\n", og1);
	
	int ft2 = ft_printf("Hello %c 42\n", 'A');
	int og2 = printf("Hello %c 42\n", 'A');
	printf("ft length is %i!\n", ft2);
	printf("og length is %i!\n\n", og2);
	
	int ft3 = ft_printf("Hello 42 %s\n", "Prague");
	int og3 = printf("Hello 42 %s\n", "Prague");
	printf("ft length is %i!\n", ft3);
	printf("og length is %i!\n\n", og3);
	
	int ft4 = ft_printf("Hello %d Prague, I like number %i\n", 42, (int)-2147483648);
	int og4 = printf("Hello %d Prague, I like number %i\n", 42, (int)-2147483648);
	printf("ft length is %i!\n", ft4);
	printf("og length is %i!\n\n", og4);
	
	int ft5 = ft_printf("Hello %u Prague, I like number %u\n", 42u, 2147483648u);
	int og5 = printf("Hello %u Prague, I like number %u\n", 42u, 2147483648u);
	printf("ft length is %i!\n", ft5);
	printf("og length is %i!\n\n", og5);
	
	int ft6 = ft_printf("Hello %x Prague, I like number %x\n", 42u, 3147483648u);
	int og6 = printf("Hello %x Prague, I like number %x\n", 42u, 3147483648u);
	printf("ft length is %i!\n", ft6);
	printf("og length is %i!\n\n", og6);
	
	int ft7 = ft_printf("Hello %X Prague, I like number %X\n", 42u, 3147483648u);
	int og7 = printf("Hello %X Prague, I like number %X\n", 42u, 3147483648u);
	printf("ft length is %i!\n", ft7);
	printf("og length is %i!\n\n", og7);
} */