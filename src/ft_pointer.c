/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:05:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/01 16:05:23 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_pointer_address(size_t x, char *base)
{
	char	string[25];
	int		i;
	int		len;
	int		temp;

	i = 0;
	len = 0;
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
		len = len + temp;
	}
	return (len);
}

int	ft_pointer(size_t x)
{
	char	base[17];
	int		len;
	int		result;

	ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	if (write(1, "0x", 2) < 0)
		return (-1);
	len = 2;
	if (x == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		len++;
	}
	else
	{
		result = ft_print_pointer_address(x, base);
		if (result < 0)
			return (-1);
		len = len + sult;
	}
	return (len);
}