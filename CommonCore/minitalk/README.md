# 📡 Minitalk

> Comunicação entre processos usando sinais UNIX (`SIGUSR1` e `SIGUSR2`)

---

## ❔ O que é

O **minitalk** é um projeto da 42 que consiste em criar um sistema de comunicação entre dois programas (cliente e servidor) utilizando **sinais UNIX** para enviar e receber mensagens.  
Este projeto reforça conhecimentos sobre manipulação de bits, sinais, comunicação entre processos e estruturas de baixo nível em C.

---

## ⚙️ Tecnologias

- Linguagem C
- Sinais UNIX (`SIGUSR1`, `SIGUSR2`)
- Funções do sistema: `signal`, `kill`, `getpid`

---

## 🔍 Conceitos Importantes

| Conceito              | Descrição                                                            |
| **SIGUSR1 / SIGUSR2** | Sinais usados para representar os bits `1` e `0`                     |
| **signal**            | Define uma função que será chamada quando um sinal for capturado     |
| **getpid**            | Obtém o PID (Process ID) do processo atual                           |
| **kill**              | Envia um sinal para um processo específico, identificando-o pelo PID |

---

## 🧭 Estrutura do Projeto

### 📨 CLIENTE

- `main`
  - Verifica se os argumentos (PID e mensagem) foram corretamente fornecidos
  - Converte o PID e envia:
    - o tamanho da mensagem com `send_size`
    - a mensagem com `send_message`

- `send_size`
  - Envia o **tamanho da mensagem em bits**
  - Utiliza `SIGUSR1` para representar `1` e `SIGUSR2` para representar `0`

- `send_message`
  - Envia **caractere por caractere**
  - Cada caractere é transformado em bits e enviado por sinais

---

### 🖥️ SERVIDOR

- `main`
  - Imprime o **PID do servidor** (necessário para o cliente)
  - Define os **handlers de sinal**:
    - Primeiro para o tamanho da mensagem
    - Depois para o conteúdo da mensagem

- `handler_signal`
  - Captura os sinais `SIGUSR1` e `SIGUSR2`
  - Constrói o **tamanho da mensagem** com base nos bits recebidos
  - Quando o tamanho está completo, altera o handler para `handler_message`

- `handler_message`
  - Recebe os sinais representando os bits da mensagem
  - Constrói cada **caractere** e armazena na mensagem final
  - Quando a mensagem está completa, imprime no terminal
