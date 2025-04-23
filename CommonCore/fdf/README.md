# FDF - Visualização de Mapas 3D

## 📋 Objetivo

O **FDF** é um projeto que tem como objetivo criar um visualizador 3D de mapas a partir de um arquivo com coordenadas. A visualização do mapa será feita utilizando uma projeção isométrica, renderizada em uma janela gráfica com a **MiniLibX**, permitindo a visualização e interação com o mapa.

---

## 🚀 Funcionalidades

- **Visualização de Mapa em 3D:** Exibe o mapa com projeção isométrica.
- **Desenho de Linhas:** Utiliza o algoritmo de **Bresenham** para desenhar as linhas entre os pontos.
- **Interatividade:** Suporte a movimentos e zoom do mapa.
- **Gestão de Janela:** Implementação da interface gráfica utilizando a MiniLibX.

---

## ⚙️ Funcionalidades da MiniLibX

- **Funções de Inicialização:**
  - `mlx_init()`: Inicializa a biblioteca **MiniLibX**.
  - `mlx_new_window()`: Cria uma nova janela.
  - `mlx_destroy_window()`: Destrói a janela.

- **Funções de Imagem:**
  - `mlx_new_image()`: Cria uma nova imagem.
  - `mlx_get_data_addr()`: Obtém o endereço de memória da imagem.
  - `mlx_put_image_to_window()`: Coloca a imagem na janela.

- **Funções de Texto:**
  - `mlx_string_put()`: Coloca uma string na janela.

- **Ganchos de Eventos:**
  - `mlx_loop_hook()`: Conecta funções ao loop de eventos.
  - `mlx_loop()`: Executa o loop de eventos.

---

## 🛠️ Etapas do Projeto

1. **Compreender a Biblioteca MiniLibX:** Entender as funções essenciais para criar a janela e manipular imagens.
2. **Leitura de Arquivo:** Processar o arquivo de entrada para obter as coordenadas do mapa.
3. **Desenho de Linhas (Algoritmo de Bresenham):** Usar o algoritmo para desenhar linhas entre pontos.
4. **Projeção Isométrica:** Aplicar a transformação para uma visualização 3D.
5. **Implementação de Translação e Zoom:** Permitir movimentos e zoom no mapa.

---

## 🔢 Algoritmo de Bresenham

O algoritmo de **Bresenham** é utilizado para desenhar linhas entre os pontos do mapa de forma eficiente:

1. **Cálculos:**
   - `Δx = x2 − x1`
   - `Bigger = max(Δx, Δy)`
   - `P_a = Δx / Bigger`
   - `P_b = Δy / Bigger`

2. **Desenho de Linha:** 
   - Continuar somando `P_a` e `P_b` aos pontos iniciais até alcançar o ponto final.

---

## 🗺️ Projeção Isométrica

A projeção isométrica é uma transformação que rotaciona os pontos 3D para exibição 2D, aplicando rotações nos eixos **X** e **Y**. A rotação no eixo **Z** é descartada.

- **Rotação de 35.264°** no eixo **X**.
- **Rotação de 45°** no eixo **Y**.

Função de transformação isométrica:

```c
void isometric(t_point *dot, double angle) {
  dot->x = (dot->x - dot->y) * cos(angle);
  dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}
```
→ Projeção de ponto
Calculate for each point:
x(2D) = x'− z′
y(2D) = y' - z′

→ Draw map
- To print the map centered in the middle of the window, we need to subtract half of the map's width from x and half of the map's height from y

```c
void draw(t_point **matrix, t_fdf *data)
{
  int y;
  int x;

  y = 0;
  while (matrix[y])
  {
    x = 0;
    while (1)
    {
      if (matrix[y + 1)
        draw_line(matrix[x][y], matrix[y+1][x], data);
      if (!matrix[y][x].is_last)
        draw_line(matrix[y][x], matrix[y][x+1], data);
      if (matrix[y][x].is_last)
        break ;
      x++;
    }
    y++;
}
push_image_to_window(dat
menu(data);
}
```

→ Translation
- Add two variables to the structure: direction y and direction x

`a→x += WIN_WIDTH / 2 + x_translate;`
`b→x += WIN_WIDTH / 2 + x_translate;`
`a→y += WIN_HEIGHT / 2 + y_translate;`
`b→y += WIN_HEIGHT / 2 + y_translate;`

→ Zoom
- The same applies to zoom.
Choose a pair of keys that, whenever pressed, will increase or decrease the zoom factor mentioned earlier, depending on whether you want to zoom in or out.
