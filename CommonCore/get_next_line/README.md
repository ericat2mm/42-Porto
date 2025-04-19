# 📄 get_next_line

> Projeto da 42 para desenvolver uma função que lê uma linha de um ficheiro por chamada.

---

## ✅ Objetivo

Criar uma função chamada `get_next_line` que retorna uma linha de um file descriptor (fd) de cada vez, até ao final do ficheiro. A função deve gerir eficientemente a memória e permitir múltiplas chamadas consecutivas.

---

## 🧠 Conceitos Envolvidos

- Leitura de ficheiros em C
- Alocação dinâmica de memória
- Manipulação de buffers
- Gerenciamento de múltiplos file descriptors
- Manipulação de strings

---

# 🗂️ Code explanation

→ ft_get_next_line

- Main function that calls `read_file` to get the data from the file, then uses `ft_line` to get the current line and `ft_next` to prepare the buffer for the next call.

- Returns the current line on each call, until reaching the end of the file.

→ read_file

- Read the file in parts (BUFFER_SIZE) and concatenate these parts into the result (`res`).

- Manages dynamic memory allocation and handles errors.

→ft_line

- Return the current line from the buffer without moving to the next line

- Use dynamic memory allocation to create a new storage space.

→ ft_next

- Return the next line from the buffer, moving the buffer pointer to the next position after the line

- Free the memory of the old buffer.
