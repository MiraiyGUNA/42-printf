/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:39:27 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/02 14:40:17 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h" // Inclui o teu ft_printf ou declara aqui
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

void	run_bonus_test(const char *test_name, const char *format, ...)
{
	va_list	args;
	char	printf_buff[1000];
	char	ft_printf_buff[1000];

	int ret_printf, ret_ft_printf;
	printf(YELLOW "\n[%s]\n" RESET, test_name);
	printf(BLUE "FORMATO: \"%s\"\n" RESET, format);
	// Captura printf oficial
	va_start(args, format);
	ret_printf = vsnprintf(printf_buff, sizeof(printf_buff), format, args);
	va_end(args);
	// Captura ft_printf (se suportar va_list)
	va_start(args, format);
	ret_ft_printf = vsnprintf(ft_printf_buff, sizeof(ft_printf_buff), format,
			args);
	va_end(args);
	printf("printf:    [%s] (ret=%d)\n", printf_buff, ret_printf);
	printf("ft_printf: [%s] (ret=%d)\n", ft_printf_buff, ret_ft_printf);
	if (ret_printf == ret_ft_printf && strcmp(printf_buff, ft_printf_buff) == 0)
		printf(GREEN "✅ PASSOU!\n" RESET);
	else
		printf(RED "❌ FALHOU!\n" RESET);
}

int	main(void)
{
	// ----- TESTES DOS BÔNUS -----
	// Flags: -0. + espaço #
	// 1. Testes com números (%d, %i)
	run_bonus_test("Bônus 1: Alinhamento à esquerda ('-')", "%-10d", 42);
	run_bonus_test("Bônus 2: Preenchimento com zeros ('0')", "%010d", 42);
	run_bonus_test("Bônus 3: Precisão ('.')", "%.5d", 42);
	run_bonus_test("Bônus 4: Sinal explícito ('+')", "%+d", 42);
	run_bonus_test("Bônus 5: Espaço para positivos (' ')", "% d", 42);
	run_bonus_test("Bônus 6: Combinação '-0.'", "% -10.5d", 42);
	run_bonus_test("Bônus 7: Largura + Precisão", "%10.5d", 12345);
	// 2. Testes com hex (%x, %X)
	run_bonus_test("Bônus 8: '#' em hex (0x)", "%#x", 255);
	run_bonus_test("Bônus 9: '#' em HEX (0X)", "%#X", 255);
	run_bonus_test("Bônus 10: Hex com '0' e largura", "%010x", 255);
	// 3. Testes com strings (%s)
	run_bonus_test("Bônus 11: Precisão em strings", "%.5s", "abcdef");
	run_bonus_test("Bônus 12: Largura + Precisão em strings", "%10.5s",
		"abcdef");
	// 4. Testes extremos
	run_bonus_test("Bônus 13: INT_MIN com flags", "%+10d", INT_MIN);
	run_bonus_test("Bônus 14: Zero com precisão", "%.5d", 0);
	run_bonus_test("Bônus 15: Combinação maluca", "%# +-20.10x", 12345678);
	return (0);
}
