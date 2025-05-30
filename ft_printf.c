/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:47:27 by mjusta            #+#    #+#             */
/*   Updated: 2025/05/30 16:19:39 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
/* 	else if (specifier == "p")
		// print void pointer in hexadecimal format
		return ;
	else if (specifier == "d")
		// print decimal number (base 10)
		return ; 
	else if (specifier == "i")
		// print integer (base 10)
		return ; 
	else if (specifier == "u")
		// print unsigned decimal number (base 10)
		return ; 
	else if (specifier == "x")
		// print number in hexadecimal(base 16) lowercase
		return ; 
	else if (specifier == "X")
		// print number in hexadecimal(base 16) uppercase
		return ; 
	else if (specifier == "%")
		// print percent sign
		return ; 
 */	return (0);
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

#include <stdio.h>
int main(void)
{
	int ft1 = ft_printf("Hello 42\n");
	int og1 = printf("Hello 42\n");
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
}