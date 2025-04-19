# 🧩 push_swap

O **push_swap** é um projeto da 42 School cujo objetivo é ordenar uma lista de inteiros utilizando apenas operações específicas entre duas pilhas — `stack_a` e `stack_b`.

---

## 📌 Objetivo

- Ordenar uma lista de números inteiros usando apenas operações de pilhas.
- Respeitar as restrições impostas (sem usar funções de ordenação prontas).
- Otimizar o número de operações.
- Utilizar algoritmos eficientes como o algoritmo turco.

---

## 🧠 Pseudo-Código Geral

1. Declarar ponteiros para `stack_a` e `stack_b`, ambos inicializados como `NULL`.
2. Tratar os dois tipos de input (string ou múltiplos argumentos).
3. Converter cada argumento para `long` e adicionar em `stack_a`.
4. Verificar por:
   - Erros de sintaxe
   - Números duplicados
   - Overflow
5. Verificar se `stack_a` já está ordenada.
6. Se não estiver, escolher o algoritmo de ordenação apropriado:
   - `sort_three`
   - `sort_five`
   - `big_sort` (Algoritmo Turco)

---

## 🧮 Algoritmo Turco

### → Push de `a` para `b`

- Repetir até que `stack_a` tenha apenas 3 elementos.
- A cada iteração, selecionar o valor mais barato para mover.
- Determinar o `target_node` ideal na `stack_b`.
  - O alvo é o número **mais próximo menor**.
  - Se não houver, usar o maior da `stack_b`.
- Calcular o custo total (push_cost):
  - Distância até o topo de `a`
  - Distância até o `target_node` em `b`

### → Push de `b` para `a`

- Para cada elemento em `b`, determinar o `target_node` em `a`.
  - O alvo é o número **mais próximo maior**.
  - Se não houver, usar o menor da `stack_a`.
- Repetir até que `stack_b` esteja vazia.

---

## ⚙️ Principais Funções

### 🔍 Algorithm Utils

| Função         | Descrição                                                                 |
|----------------|--------------------------------------------------------------------------|
| `stack_size`   | Retorna o tamanho da pilha                                               |
| `get_biggest`  | Retorna o maior valor da pilha                                           |
| `sorted`       | Verifica se a pilha está ordenada                                        |
| `get_position` | Retorna a posição de um valor específico                                 |

### 🧠 Algoritmos

| Função        | Descrição                                                                 |
|---------------|--------------------------------------------------------------------------|
| `sort_three`  | Ordena 3 elementos com rotações e swaps                                   |
| `sort_five`   | Usa `stack_b` para isolar o maior/menor e usa `sort_three`                |
| `big_sort`    | Implementa o algoritmo turco para ordenar listas maiores                  |
| `sort_until_three` | Move elementos para `b` até restarem 3 em `a`                        |
| `back_to_a`   | Move os elementos de volta de `b` para `a` ordenadamente                  |

### 🛠️ Big Sort Utils

| Função             | Descrição                                                             |
|--------------------|----------------------------------------------------------------------|
| `get_tar_val_a`    | Encontra o melhor lugar em `a` para inserir um valor de `b`          |
| `get_tar_val_b`    | Encontra o melhor lugar em `b` para inserir um valor de `a`          |
| `get_cheapest`     | Calcula qual valor tem o menor custo total para mover                |
| `get_total`        | Soma os custos de rotação das pilhas                                 |
| `target_dist`      | Calcula quantas rotações são necessárias para alcançar um target     |

### 📦 Insert Stacks

| Função           | Descrição                                                               |
|------------------|------------------------------------------------------------------------|
| `create`         | Cria um nó a partir de uma string                                       |
| `insert_to_stacks` | Insere os números em `stack_a` usando `insert_to_last`               |
| `insert_to_last` | Insere um nó ao final da pilha                                          |
| `free_stacks`    | Liberta a memória usada pelas pilhas                                    |

---

## 🚀 push_swap

### → `main`

1. Inicializa as pilhas `stack_a` e `stack_b`.
2. Verifica os argumentos recebidos.
3. Processa os números, converte-os e cria a pilha.
4. Verifica se a pilha já está ordenada.
5. Se não estiver, chama a função `push_swap`.

### → `push_swap`

- Decide entre `sort_three`, `sort_five` ou `big_sort` conforme o tamanho da `stack_a`.

---

## 🔁 Operações

### 🔃 Push

| Função | Descrição |
|--------|-----------|
| `push` | Move o topo de uma pilha para a outra |

### 🔁 Reverse Rotate

| Função               | Descrição                                     |
|----------------------|----------------------------------------------|
| `reverse_rotate`     | Move o último elemento para o topo           |
| `reverse_rotate_both`| Aplica a operação nas duas pilhas            |

### 🔄 Rotate

| Função         | Descrição                                     |
|----------------|----------------------------------------------|
| `rotate`       | Move o primeiro elemento para o fim           |
| `rotate_both`  | Aplica a rotação nas duas pilhas              |

### 🔁 Swap

| Função | Descrição                                  |
|--------|---------------------------------------------|
| `swap` | Troca os dois primeiros elementos da pilha |

---
