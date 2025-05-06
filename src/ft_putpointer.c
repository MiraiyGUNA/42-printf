/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:05:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/06 14:12:56 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_pointer_address(size_t x, const char *base)
{
	char	string[20];
	int		i;
	int		length;
	int		result;

	i = 0;
	length = 0;
	while (x != 0)
	{
		string[i++] = base[x % 16];
		x = x / 16;
	}
	while (i--)
	{
		result = ft_putchar_fd(string[i], 1);
		if (result < 0)
			return (-1);
		length = length + result;
	}
	return (length);
}

int	ft_putpointer(size_t x)
{
	const char	*base;
	int			length;
	int			result;

	base = "0123456789abcdef";
	length = 0;
	if (write(1, "0x", 2) < 0)
		return (-1);
	length = length + 2;
	if (x == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (length + 1);
	}
	result = ft_print_pointer_address(x, base);
	if (result < 0)
		return (-1);
	return (length + result);
}
