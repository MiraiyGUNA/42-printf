### Função `print_pointer_address(size_t x, char *base)`

Esta função é responsável por converter o valor do ponteiro para uma representação hexadecimal e imprimir cada caractere individualmente:

1. **Conversão para Hexadecimal**  
   - Usa um array `string[25]` para armazenar os caracteres hexadecimais.
   - Calcula cada dígito através da operação `x % 16`, onde `x` é dividido sucessivamente por 16, armazenando os caracteres da base (os dígitos hexadecimais `0-9` e `a-f`).
   - Os caracteres são inseridos no array na ordem inversa.
2. **Impressão dos Caracteres**  
   - Após armazenar os caracteres, um loop percorre `string` em ordem reversa para imprimir os caracteres com `ft_putchar_fd_l(string[i], 1)`.
   - Se houver erro na impressão (`temp < 0`), a função retorna `-1`.

### Função `ft_pointer(size_t x)`

Esta função encapsula a lógica de impressão de um ponteiro, garantindo que o formato siga o padrão `"0x"` seguido do valor hexadecimal.
1. **Inicializa a Base**  
   - Usa `ft_strlcpy(base, "0123456789abcdef", sizeof(base))` para definir a tabela de conversão hexadecimal.
2. **Imprime o Prefixo `"0x"`**  
   - Adiciona `"0x"` à saída padrão, representando que o valor será exibido em formato hexadecimal.
3. **Lida com o Caso Especial `x == 0`**  
   - Se `x` for `0`, imprime `"0"`, pois um ponteiro nulo (`NULL`) deve ser representado como `"0x0"`.
4. **Chama `print_pointer_address(x, base)`**  
   - Se `x` não for `0`, usa a função `print_pointer_address()` para imprimir a parte hexadecimal correspondente.

### Por que foi implementado assim?

- **Manipulação Manual do Hexadecimal:** Evita funções prontas como `sprintf` ou `printf`, permitindo um controle mais direto sobre a saída.
- **Evita Dependências Externas:** É útil em projetos como `ft_printf`, onde se deseja implementar uma versão simplificada de `printf`.
- **Gestão de Erros:** Implementa verificações de erro para garantir que a escrita ocorre corretamente.

Se quiser aprofundar mais algum detalhe, estou aqui para ajudar! 🚀

1. Porque e que criamos uma string de tamanho 25? O facto de alocar 26 e especial ou poderia simplesmente criar um `char *string` e isso nao haveria problema?
2. Fazemos de ordem reversa, por que razao em especifico?
3. Consegues explicar a logica por tras do `0123456789abcdef`? Como e que este pedaco de codigo, funciona para com o codigo inteiro?

Ótimas perguntas! Vamos analisá-las uma a uma. 🚀

### 1. Por que usamos `char string[25]`? Poderíamos usar `char *string`?

A escolha de um array de tamanho fixo (`char string[25]`) garante que temos um espaço reservado na pilha para armazenar a conversão do número. O número 25 foi escolhido porque um endereço de memória em sistemas de 64 bits tem, no máximo, 16 caracteres em hexadecimal (por exemplo, `0xffffffffffffffff`). No entanto, como estamos armazenando caracteres individualmente, um tamanho maior pode ter sido escolhido por segurança.

Se usássemos `char *string`, precisaríamos de **alocação dinâmica** (`malloc`), o que exigiria gerenciamento de memória e uso de `free()`. Neste caso, um array estático facilita a implementação sem precisar lidar com desalocação de memória.

### 2. Por que imprimimos em ordem reversa?

A razão principal está na forma como convertemos números para diferentes bases:

- Quando obtemos os dígitos hexadecimais, começamos pegando o **resto da divisão por 16** (`x % 16`), armazenamos esse valor, e então dividimos `x` sucessivamente por 16.
- O primeiro dígito armazenado será o **menos significativo** (o último que deve ser impresso).
- Para mostrar o número corretamente, precisamos percorrer o array de trás para frente, garantindo que os dígitos sejam impressos na ordem correta.

Exemplo:

```
x = 1234
1. 1234 % 16 -> '2' (salvado primeiro)
2. 1234 / 16 = 77
3. 77 % 16 -> 'd' (salvado segundo)
4. 77 / 16 = 4
5. 4 % 16 -> '4' (salvado terceiro)
```
Se imprimíssemos na ordem de inserção, o resultado seria `"2d4"`, o que estaria invertido.

### 3. Qual a lógica do `"0123456789abcdef"`?

Este array representa a **base hexadecimal**, que usa os caracteres `0-9` e `a-f` para representar números de `0` a `15`. Ele funciona como uma **tabela de conversão** para transformar restos de divisão (`x % 16`) em caracteres:

Exemplo:

- `x % 16 = 10` → `base[10] = 'a'`
- `x % 16 = 15` → `base[15] = 'f'`
- `x % 16 = 3` → `base[3] = '3'`

Este mecanismo nos permite usar `base[x % 16]` para obter diretamente o caractere correspondente.

### Resumo

1. O tamanho 25 do array é por segurança, evitando alocação dinâmica.
2. A ordem reversa é necessária porque a conversão de base começa com os dígitos menos significativos.
3. `"0123456789abcdef"` é essencial para mapear corretamente números decimais para hexadecimal.

