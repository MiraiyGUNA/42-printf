/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:30:54 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/02 15:23:48 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_printf_char(char c)
{
	if (a == 'c' || a == 's' || a == 'p' || a == 'd' || a == 'i' || a == 'u'
		|| a == 'x' || a == 'X' || a == '%')
		return (1);
	return (0);
}

static int	ft_send_to_correct_function(va_list args, char c, int *plength)
{
	int	temp;

	temp = 0;
	if (c == 'c')
		temp = ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		temp = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		temp = ft_pointer(va_arg(args, size_t));
	else if (c == 'd' || c == 'i')
		temp = ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		temp = ft_u_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		temp = ft_hexadecimal(va_arg(args, unsigned int), c);
	else if (c == '%')
		temp = ft_putchar_fd('%', 1);
	else
		return (-1);
	if (temp < 0)
		*plength = -1;
	else
		*plength = *plength + temp;
	return (*plength);
}

static int	ft_format_check(const char *format, va_list args, int *plength)
{
	int	length;

	length = *plength;
	while (*format)
	{
		if (*format == '%' && ft_is_printf_char(*(format + 1)))
		{
			length = ft_send_to_correct_function(args, *(format + 1), &len);
			if (length < 0)
				return (-1);
			format++
		}
		else
		{
			length = length + ft_putchar_fd(*format, 1);
			if (length < 0)
				return (-1);
		}
		format++;
	}
	*plength = length;
	return (0);
}


int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	if(ft_format_check(format, args, &length) < 0)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return(length);
}
