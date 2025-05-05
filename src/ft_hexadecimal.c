/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:03:34 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/05 13:03:34 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	print_hexadecimal(unsigned int x, const char *base)
{
	char	string[9]; // até 8 dígitos para 32-bit unsigned int + segurança extra
	int		i;
	int		length;
	int		temp;

    i = 0;
    length = 0;
	while (x != 0)
	{
		string[i] = base[x % 16];
		i++;
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

int	ft_hexadecimal(unsigned int x, char format)
{
	const char	*base;
	int			result;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";

	if (x == 0)
		return (ft_putchar_fd('0', 1));

	result = print_hexadecimal(x, base);
	if (result < 0)
		return (-1);
	return (result);
}
