/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:47:35 by mjusta            #+#    #+#             */
/*   Updated: 2025/06/02 11:32:17 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *, ...);
int	ft_putchar(const char c);
int ft_putstr(const char *s);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int ft_puthex(unsigned int n, int upper);

#endif