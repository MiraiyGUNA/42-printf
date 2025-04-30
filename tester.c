#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Simulando a função ft_printf da biblioteca libftprintf
int ft_printf(const char *format, ...) {
    if (format == NULL) return 0;

    va_list args;
    va_start(args, format);

    // Aqui você deve implementar sua lógica de formatação e impressão.
    // Este exemplo simplesmente imprime "Teste" para verificar a função.

    char output[1024];
    int len = vsnprintf(output, sizeof(output), format, args);
    va_end(args);

    if (len < 0) {
        return -1; // Erro ao escrever na string
    }

    printf("%s", output); // Impressão da saída

    return strlen(output);
}

int main() {

    #define TEST_ASSERT(expr, msg) \
        do { \
            int result = expr; \
            if (result != 0) { \
                fprintf(stderr, "Test failed: %s\n", msg); \
                exit(EXIT_FAILURE); \
            } \
        } while(0)

    // Teste para verificar a impressão de caracteres
    TEST_ASSERT(ft_printf("'%c'\n", 'A') == printf("'%c'\n", 'A'), "Teste de caractere falhou");
    
    // Teste para verificar a impressão de strings
    char *test_str = "Hello, World!";
    TEST_ASSERT(ft_printf("%s\n", test_str) == printf("%s\n", test_str), "Teste de string falhou");

    // Teste para verificar a impressão de inteiros (signed)
    TEST_ASSERT(ft_printf("Integer: %d, %i\n", 12345, -6789) == printf("Integer: %d, %i\n", 12345, -6789), "Teste de inteiro falhou");

    // Teste para verificar a impressão de unsigned inteiros
    TEST_ASSERT(ft_printf("Unsigned Integer: %u\n", 0xFFFFFFFF) == printf("Unsigned Integer: %u\n", 0xFFFFFFFF), "Teste de unsigned inteiro falhou");

    // Teste para verificar a impressão em hexadecimal (minúsculas)
    TEST_ASSERT(ft_printf("Hexadecimal (lowercase): %x, Hexadecimal (uppercase): %X\n", 255, 255) == printf("Hexadecimal (lowercase): %x, Hexadecimal (uppercase): %X\n", 255, 255), "Teste de hexadecimal falhou");

    // Teste para verificar a impressão de endereços de memória
    char *ptr = "Hello";
    TEST_ASSERT(ft_printf("Pointer: %p\n", ptr) == printf("Pointer: %p\n", ptr), "Teste de ponteiro falhou");

    // Teste para verificar o uso do sinal (+)
    TEST_ASSERT(ft_printf("Signed Integer with sign flag: %+d, %+i\n", -123456, 78901) == printf("Signed Integer with sign flag: %+d, %+i\n", -123456, 78901), "Teste de sinal (+) falhou");

    // Teste para verificar alinhamento com zeros
    TEST_ASSERT(ft_printf("Left Aligned with zero padding: %05d, Left Aligned with space padding: %-5d\n", 1234, -5678) == printf("Left Aligned with zero padding: %05d, Left Aligned with space padding: %-5d\n", 1234, -5678), "Teste de alinhamento com zeros falhou");

    // Teste para verificar o uso do símbolo hash (#)
    TEST_ASSERT(ft_printf("Hexadecimal with hash flag: %#x, Hexadecimal without hash flag: %x\n", 16, 16) == printf("Hexadecimal with hash flag: %#x, Hexadecimal without hash flag: %x\n", 16, 16), "Teste de símbolo hash (#) falhou");

    // Teste para verificar o caractere literal %
    TEST_ASSERT(ft_printf("Special character: %%\n") == printf("Special character: %%\n"), "Teste de caractere literal % falhou");

    fprintf(stderr, "Todos os testes foram aprovados!\n");

    return 0;
}
