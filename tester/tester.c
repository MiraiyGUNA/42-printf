/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:39:13 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/02 14:40:01 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"

void	run_test(const char *format, ...)
{
	char	printf_buff[1024];
	char	ft_printf_buff[1024];

	va_list args1, args2;
	int ret_printf, ret_ft_printf;
	// Captura output do printf
	va_start(args1, format);
	ret_printf = vsnprintf(printf_buff, sizeof(printf_buff), format, args1);
	va_end(args1);
	// Captura output do ft_printf (se estiver a escrever para um buffer)
	va_start(args2, format);
	ret_ft_printf = vsnprintf(ft_printf_buff, sizeof(ft_printf_buff), format,
			args2); // Se o teu ft_printf suportar va_list
	// Se não suportar, tens de adaptar aqui!
	va_end(args2);
	printf(YELLOW "\nTeste: [" RESET "%s" YELLOW "]\n" RESET, format);
	printf("printf:    [%s] (ret=%d)\n", printf_buff, ret_printf);
	printf("ft_printf: [%s] (ret=%d)\n", ft_printf_buff, ret_ft_printf);
	if (ret_printf == ret_ft_printf && strcmp(printf_buff, ft_printf_buff) == 0)
		printf(GREEN "✅ PASSOU!\n" RESET);
	else
		printf(RED "❌ FALHOU!\n" RESET);
}

int	main(void)
{
	// Testes básicos (podes adicionar mais)
	run_test("Char: %c", 'A');
	run_test("String: %s", "Olá 42!");
	run_test("Número: %d", 42);
	run_test("Hex: %x", 255);
	run_test("Ponteiro: %p", (void *)0x7ffeee2b4568);
	run_test("%%");
	// Testes com flags (se o teu ft_printf já as suportar)
	run_test("%10d", 123);
	run_test("%-10d", 123);
	run_test("%+d", 42);
	run_test("% d", 42);
	run_test("%#x", 255);
	return (0);
}
