# 📌 ft_printf

Este projeto é uma recriação da função `printf` da biblioteca padrão de C. O objetivo é imprimir uma string formatada na saída padrão, interpretando os diferentes especificadores de formato e argumentos variáveis.

---

## ✅ Objetivo

- Reproduzir o comportamento da função `printf`
- Manipular argumentos variáveis com `stdarg.h`
- Trabalhar com diferentes tipos de dados (char, int, string, ponteiros, etc.)
- Desenvolver uma função robusta e modular com boas práticas de C

---

## 🧠 Como funciona

### 🔧 `ft_printf`

- Recebe uma *format string* com argumentos adicionais.
- Itera sobre cada caractere da string.
  - Quando encontra `%`, chama `ft_print_type` para processar o especificador.
  - Caso contrário, imprime o caractere diretamente na saída padrão.
- Retorna o número total de caracteres impressos.

### 🎯 `ft_print_type`

- Identifica o tipo de especificador (ex: `%d`, `%s`, `%x`, etc.).
- Chama a função apropriada para imprimir o valor.
- Usa a lista de argumentos variáveis (`va_list`).
- Retorna o número de caracteres impressos.

### 🔢 `ft_print_base`

- Converte e imprime um número em qualquer base (por exemplo, hexadecimal ou decimal).
- Usa recursão para dividir o número e imprimir os dígitos na ordem correta.
- Retorna a contagem total de caracteres impressos.

### 🧭 `ft_print_ptr`

- Imprime o valor de um ponteiro em formato hexadecimal.
- Prefixa o valor com `0x`.
- Retorna o número de caracteres impressos.

---

## 📚 Especificadores suportados

| Especificador | Significado            |
|---------------|------------------------|
| `%c`          | Caractere              |
| `%s`          | String (char *)        |
| `%p`          | Ponteiro (void *)      |
| `%d` / `%i`   | Inteiros (int)         |
| `%u`          | Inteiro sem sinal      |
| `%x` / `%X`   | Hexadecimal (min/mai)  |
| `%%`          | Caractere de porcentagem literal |

