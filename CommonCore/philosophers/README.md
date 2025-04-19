# 🧠 Philosophers

O projeto **Philosophers** simula o clássico problema dos filósofos com o objetivo de aplicar conceitos de concorrência e evitar condições como _deadlock_ e _starvation_.

---

## 📖 Visão Geral

- Um ou mais filósofos sentam-se à volta de uma mesa.
- Os filósofos alternam entre pensar, comer e dormir.
- Há tantos garfos quanto filósofos.
- Um filósofo precisa de **dois garfos** para comer.
- Quando termina de comer, o filósofo **liberta os garfos**, dorme e depois volta a pensar.
- A simulação termina quando **um filósofo morre de fome**.

---

## 📌 Requisitos

O programa deve receber os seguintes argumentos:

1. Número de filósofos (também o número de garfos)
2. Tempo para morrer (`time_to_die`)
3. Tempo para comer (`time_to_eat`)
4. Tempo para dormir (`time_to_sleep`)
5. (Opcional) Número de vezes que cada filósofo deve comer

---

## 🧵 Threads

- Cada filósofo é representado por **uma thread**.
- Threads partilham o mesmo espaço de memória, mas cada uma tem a sua própria stack e registradores.
- A sincronização entre threads é feita com **mutexes**.

---

## 🔒 Mutex

- Usado para **proteger os garfos** e evitar acessos simultâneos.
- Cada garfo é protegido por um mutex.
- Isso impede que dois filósofos tentem usar o mesmo garfo ao mesmo tempo.

---

## ⚙️ Estrutura do Programa

### 🛠️ Inicialização

- Lê os argumentos e configura o estado global.
- Aloca memória para filósofos, threads e garfos.
- Inicializa todos os mutexes.

### 🧍 Configuração dos Filósofos

- Define as propriedades de cada filósofo.
- Cada filósofo tem ponteiros para seus garfos esquerdo e direito.

### 🔁 Execução

- Cria uma thread para cada filósofo.
- Cada thread executa a rotina do filósofo, que inclui:
  - **Pensar**
  - **Pegar os garfos (com mutex)**
  - **Comer**
  - **Largar os garfos**
  - **Dormir**

### 📌 Evitar Deadlocks

- Usa um **mutex de controle** para coordenar os acessos aos garfos.
- Se o filósofo não conseguir pegar os dois garfos, ele **liberta o que conseguiu** e tenta novamente depois.
- Pequenas esperas são inseridas com `usleep` para reduzir a chance de starvation.

### 🧹 Cleanup

- Após o término da simulação:
  - Espera o fim de todas as threads.
  - Destroi todos os mutexes.
  - Liberta a memória alocada.

---

## 🛏️ Comportamentos Temporizados

### 🧠 Pensar

- Após dormir, o filósofo pensa por um tempo aleatório.
- Isso ajuda a evitar tentativas contínuas de comer, reduzindo contenções.

### 🍽️ Comer

- O filósofo pega os dois garfos (se disponíveis), atualiza o tempo da última refeição e come.

### 😴 Dormir

- Após comer, o filósofo dorme por um tempo definido, simulando descanso.
