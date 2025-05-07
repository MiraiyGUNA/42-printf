/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:05:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/07 13:56:03 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_pointer_address(size_t x, char *base)
{
	char	string[25];
	int		i;
	int		length;
	int		temp;

	i = 0;
	length = 0;
	while (x != 0)
	{
		string[i++] = base[x % 16];
		x = x / 16;
	}
	while (i--)
	{
		temp = ft_putchar_fd(string[i], 1);
		if (temp < 0)
			return (-1);
		length = length + temp;
	}
	return (length);
}

int	ft_putpointer(size_t x)
{
	char	base[17];
	int		length;
	int		result;

	ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	if (x == 0)
	{
		if (write(1, "(nil)", 5) < 0)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) < 0)
		return (-1);
	length = 2;
	result = print_pointer_address(x, base);
	if (result < 0)
		return (-1);
	length = length + result;
	return (length);
}
